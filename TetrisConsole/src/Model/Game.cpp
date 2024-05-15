#include "Game.h"
#include <random>
#include <utility>

Game::Game(): rules(10000000 , 60*60 /* nbSecond*nbMinute */, 200 , 20),
    state(State::PLAYING),
    score(0),
    startTime(NULL),
    level(1){

    canDrop = true;
    currentBrick = bag.nextShape();
    insertBrickToBoard();
    listOfSpeedLevel = {60000 , 53000 , 49000 , 45000 , 41000 , 37000 , 33000 , 28000 , 23000 , 18000 ,
    13000, 9000 , 8000 , 8000 , 7000 , 6000 ,5000 , 4000 , 3000 , 2000 };
}

const Board& Game::getBoard()const{
    return board ;
}

State Game::getState() const {
    return state ;
}
int Game::getLevel()const{
    return level ;
}

int Game::getScore(){
    return score;
}

void Game::setState(State newState){
    state = newState ;
}

void Game::insertBrickToBoard(){

    listOfCurrentPositions = currentBrick->getPositionsTrue();
    Position inputPosition(0, board.getWidth()/2);
    Position gap((inputPosition.getX()-listOfCurrentPositions.front().getX()),
                 (inputPosition.getY()-listOfCurrentPositions.front().getY()));
    //it calculates the distance between the brick's shape and the left border .

    listOfCurrentPositions = brickPositionToBoardPosition(listOfCurrentPositions, gap);
    for(auto &pos : listOfCurrentPositions){
        if(board.getType(pos) != CaseType::NOT_OCCUPIED){
            setState(State::LOST);
        }
    }
    if (state == State::PLAYING){
        board.insert(listOfCurrentPositions, currentBrick->getType());
    }
}

bool Game::isGameOver()
{
    return (state==State::LOST);
}

void Game::updateStateIfWon()
{
    if(rules.isLineComplete(board) || rules.isScoreOver(score) || rules.isLevelOver(level)){
        state = State::WON;
    }
}

void Game::nextShape(){
    listOfCurrentPositions.clear();
    std::unique_ptr<Brick> nextBrickPtr = bag.nextShape();

    //std::move transfers the properties with the smart pointer to the next brick
    currentBrick = std::move(nextBrickPtr);
    insertBrickToBoard();
    canDrop=false;
}

/*
 * This methods returns the number of line completed . It was the easiest way to get it for the score .
 */
int Game::moveBrick(Direction dir, bool WithDrop){

    Position p;
    Position delta = p.getPositionFromDirection(dir);
    int nbLineCompleted = 0;
    std::vector<Position> newPositionsAfterDirection;

    for(auto& p1 :listOfCurrentPositions){
        newPositionsAfterDirection.push_back(addGap(p1, delta));
    }
    /*
     * If the next positions don't have collisions and there is no collisions with the next ones . We then place the brick at
     * the next positions .
     */
    bool hasNoCollisions = applyNewPositionsWhenValid(newPositionsAfterDirection);

    if(!hasNoCollisions){
        if(dir==Direction::RIGHT || dir==Direction::LEFT){
            board.updateCompleteLines();
        }else{
            nbLineCompleted = board.updateCompleteLines();
            nextShape();
        }
    }

    /*
     * We calculate the score differently if there is a drop or not .
     */
    if(!WithDrop){
        score += calculScore(nbLineCompleted , 0 , level);
        notifyObservers();
    }
    return nbLineCompleted ; //Returns the number of line completed after the move .
}

void Game::rotate(Rotation sens){
    std::vector<Position> rotatePositionsInBrick;
    std::vector<Position> newPositionsAfterRotate;

    currentBrick->rotate(sens);
    rotatePositionsInBrick= currentBrick->getPositionsTrue();

    //c'est le decalage ou le delta entre une pos occupée par la brique courante et une pos de la meme brique retourné
    Position gapBetweenCurrentPosAndBrickPos(
        listOfCurrentPositions.front().getX() - rotatePositionsInBrick.front().getX(),
        listOfCurrentPositions.front().getY() - rotatePositionsInBrick.front().getY());
    //It's the gap between the current brick positions and the same brick but with the rotation applied

    newPositionsAfterRotate = brickPositionToBoardPosition(rotatePositionsInBrick, gapBetweenCurrentPosAndBrickPos);
    applyNewPositionsWhenValid(newPositionsAfterRotate);
    //We the rotation is not applied on the board if the brick is obstruct or not in the board.
    notifyObservers();
}

void Game::drop()
{
    int nbLine = 0 ;
    int drop = 0 ;
    canDrop = true ;
    while(canDrop){
        nbLine = moveBrick(Direction::DOWN, true);
        drop++;
    }
    score += calculScore(nbLine , drop-1, level); //we do (drop -1) because once it's on the bottom the drop will still continue
                                                // but it doesn't count as a height .
    notifyObservers();
}

bool Game::applyNewPositionsWhenValid(const std::vector<Position> &newPositions)
{
    if(posIsInBoardHeight(newPositions) && !hasCollisions(posWithoutOldPos(newPositions))){
        for(auto& pos : listOfCurrentPositions){
            board.deleteOldBrick(pos);
        }

        board.insert(newPositions, currentBrick->getType() );
        listOfCurrentPositions = newPositions;

        return true;
    }
    return false;
}

/**
 * @brief
 * This method prevents us from looking at the old positions we were so it compares only with the
 * brick's positions that are not the current brick .
 * Else it would make collisions where there are none .
 * @param
 * Positions that we verify if we can add them to the board .
 * @return
 * The valid vector of positions .
 */

std::vector<Position> Game::posWithoutOldPos(const std::vector<Position> &newPositionsInBoard)
{
    std::vector<Position> realNewPositions;

    for (const auto& newPos : newPositionsInBoard) {
        bool isNew = true;

        // Checks if the new positions is already in the list .
        for (const auto& oldPos : listOfCurrentPositions) {
            if (newPos == oldPos) {
                isNew = false;
                break;
            }
        }

        // If the new positions is not in the actual list , we add it .
        if (isNew) {
            realNewPositions.push_back(newPos);
        }
    }

    return realNewPositions;
}

Position Game::addGap(const Position& p, Position gap){
    return Position(p.getX()+gap.getX(), p.getY()+gap.getY());
}

std::vector<Position> Game::addGapForBrickPositions(const std::vector<Position> &positionsTrue, Position gap)
{
    std::vector<Position> copiePositionsTrue;
    for (auto& position : positionsTrue) {
        copiePositionsTrue.push_back(addGap(position, gap));
    }
    return copiePositionsTrue;
}

/*
 * It will return the center positions where will be the current brick .
 */
std::vector<Position> Game::brickPositionToBoardPosition(const std::vector<Position> & positionsTrue, Position gap){
    return addGapForBrickPositions(positionsTrue, gap);
}
void Game::BoardPrefill()
{
    std::random_device rd;
    std::mt19937 gen(rd());

    int maxHeight = board.getHeight() / 2;

    // We add 3 to max height because usually a brick has 3 of height .
    while(getCurrentNbLines()< maxHeight+3){

        std::uniform_int_distribution<int> dis(1, 3);
        int randomCommand = dis(gen);

        switch(randomCommand){
        case 1 : moveBrick(Direction::DOWN, true);
            break;
        case 2 : moveBrick(Direction::LEFT, true);
            break;
        case 3 : moveBrick(Direction::RIGHT, true);
            break;
        }
    }
    board.updateCompleteLines();
}

/**
 * verifie si une ligne continet une case non vide
 * @brief Game::isHalfFill
 * @return
 */
int Game::getCurrentNbLines() {
    int currentNbLines = 0;
    for (int row = board.getHeight() - 1; row >= 0; row--) {
        for (int col = 0; col < board.getWidth(); col++) {

            // Vérifier si la ligne a au moins une case rempli
            if (board(row, col) != CaseType::NOT_OCCUPIED) {
                currentNbLines++;
                break;
            }
        }
    }
    return currentNbLines;
}

void Game::setBoard(int height, int width)
{
    board = Board(height, width);
}

bool Game::posIsInBoardWidth(const std::vector<Position> & positionsInBoard){
    for (auto& position : positionsInBoard) {
        if(!board.posIsInBoardWidth(position)){
            return false;
        }
    }
    return true;
}

bool Game::posIsInBoardHeight(const std::vector<Position> & positionsInBoard){
    for (auto& position : positionsInBoard) {
        if(!board.posIsInBoardHeight(position)){
            return false;
        }
    }
    return true;
}

/**
 * @brief
 * This method verify that the positions given don't have collisions .
 * @param
 * list of positions on the board .
 * @return
 * A boolean either it has or it doesn't have collisions .
 */

bool Game::hasCollisions(const std::vector<Position> & positionsInBoard){

    //si il y a au moins une seule collisions on reeurn false
    for(auto& p :positionsInBoard){

        if(board.getType(p) != NOT_OCCUPIED){
            return true;
        }
    }
    return false;
}
int Game::calculScore(int ligne , int drop , int niveau){
    int multiplier = 0;
    switch (ligne){
    case 1:
        multiplier = 40 ;
        break ;
    case 2:
        multiplier = 100 ;
        break ;
    case 3:
        multiplier = 300 ;
        break ;
    case 4:
        multiplier = 1200 ;
        break ;
    default :
        break ;
    }
    return (multiplier * ligne + drop)* niveau ;
}
void Game::updateLevel(){
    level = (board.getCountCompleteslines()/10)+1 ;
}
int Game::getSpeedLevel(int lvl){
    return listOfSpeedLevel.at(lvl-1);
}

