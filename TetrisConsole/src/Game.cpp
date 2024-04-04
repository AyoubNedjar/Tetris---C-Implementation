#include "Game.h"
#include <iostream>
#include <random>
#include <utility>

Game::Game(): rules(10000, 10, 50), state(State::PLAYING)  , score(0) , niveau(1) , TotalLigneComplete(0){

    canDrop = true;
    currentBrick = bag.nextShape();
    insertBrickToBoard();
}

const Board& Game::getBoard()const{
    return board ;
}

State Game::getState() const {
    return state ;
}

int * Game::getNiveau(){
    return &niveau ;
}

int Game::getScore(){
    return score;
}

int Game::getNbLigneComplete(){
    return TotalLigneComplete;
}

void Game::setState(State newState){
    state = newState ;
}

/**
 *
 * va dessiner la forme au tout debut du tableau
 * @brief Game::paintStartedBrick
 */
void Game::insertBrickToBoard(){

    listOfCurrentPositions = currentBrick->getPositionsTrue();
    Position inputPosition(0, board.getWidth()/2);
    Position gap((inputPosition.getX()-listOfCurrentPositions.front().getX()),
                 (inputPosition.getY()-listOfCurrentPositions.front().getY()));

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
    if(rules.isLineComplete(board) || rules.isScoreOver(score)){
        state = State::WON;
    }
}

/**
 * va checker si on respecte toujours les regles de jeu pour mettre a jour l'état de jeu
 * @brief Game::checkState
 */
/*void Game::checkState()
{
    //we don't use the methode for the time in this poject in console mode
    if(rules.isLineComplete(board) || rules.isScoreOver(score)){
        setState(State::LOST);
    }

}*/
/**
 * va récupérer un nouvelle brique du sac pour la mettre brique courante
 * @brief Game::nextShape
 */
void Game::nextShape(){
    listOfCurrentPositions.clear();
    std::unique_ptr<Brick> nextBrickPtr = bag.nextShape();

    //tranfert de propriété avec pointeur intelligent pour que current brique pointe vers la prochaine
    currentBrick = std::move(nextBrickPtr);
    insertBrickToBoard();
    canDrop=false;
}


int Game::moveBrick(Direction dir, bool WithDrop){

    //j aurais pu eviter de créer une nouveles liste et et voir si il est dans le board et si il y  des collisions dans
    //mais je ne connaitrai pas la raison du pq je ne peux pas bouger
    //on copie
    Position p;
    Position delta = p.getPositionFromDirection(dir);
    int nbLine = 0;
    std::vector<Position> newPositionsAfterDirection;

    for(auto& p1 :listOfCurrentPositions){

        newPositionsAfterDirection.push_back(addGap(p1, delta));

    }

    /*
         *si les procaines positions se trouventd dans le board et que il n y a pas de collisions aux prochaines nouvelles positions
         *alors on peut les placer sinon on passe a la prochaine brique
         */
    bool isInBoardAndNotHaveCollisions = applyNewPositionsWhenValid(newPositionsAfterDirection);

    if(!isInBoardAndNotHaveCollisions){
        if(dir==Direction::RIGHT || dir==Direction::LEFT){
            board.updateCompleteLines();
        }else{
            nbLine = board.updateCompleteLines();
            nextShape();
        }
    }


    if(!WithDrop){
        score += calculScore(nbLine , 0 , niveau);
        notifyObservers();
    }
    return nbLine ; //Returns the number of line completed after the move .
}

void Game::rotate(Rotation sens){
    std::vector<Position> rotatePositionsInBrick;
    std::vector<Position> newPositionsAfterRotate;

    currentBrick->rotate(sens);
    rotatePositionsInBrick= currentBrick->getPositionsTrue();

    //c'est le decalage ou le delta entre une pos occupée par la brique courante et une pos de la meme brique retourné
    Position gapBetweenPosCurrentAndPosInBrick(
        listOfCurrentPositions.front().getX() - rotatePositionsInBrick.front().getX(),
        listOfCurrentPositions.front().getY() - rotatePositionsInBrick.front().getY());

    newPositionsAfterRotate = brickPositionToBoardPosition(rotatePositionsInBrick, gapBetweenPosCurrentAndPosInBrick);
    applyNewPositionsWhenValid(newPositionsAfterRotate);
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
    score += calculScore(nbLine , drop-1, niveau);
    notifyObservers();
}

bool Game::applyNewPositionsWhenValid(const std::vector<Position> &newPositions)
{
    if(inBoardHeight(newPositions) && !hasCollisions(posWithoutOldPos(newPositions))){
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
 * retourne les positons rééelles du plateau sans les ancienne sinon on recompare les même
 * @brief Game::posWithoutOldPos
 * @param newPositionsInBoard
 * @return
 */
std::vector<Position> Game::posWithoutOldPos(const std::vector<Position> &newPositionsInBoard)
{
    std::vector<Position> realNewPositions;

    for (const auto& newPos : newPositionsInBoard) {
        bool isNew = true;

        // Vérifier si la nouvelle position est déjà dans la liste actuelle
        for (const auto& oldPos : listOfCurrentPositions) {
            if (newPos == oldPos) {
                isNew = false;
                break;
            }
        }

        // Si la nouvelle position n'est pas dans la liste actuelle, l'ajouter à la liste des nouvelles positions
        if (isNew) {
            realNewPositions.push_back(newPos);
        }
    }

    return realNewPositions;
}

/**
 * retourne une nouvelles position à laquelle on a ajouter un delta(décalage)
 * @brief addGap
 */
Position Game::addGap(const Position& p, Position gap){
    return Position(p.getX()+gap.getX(), p.getY()+gap.getY());
}


std::vector<Position> Game::addGapForTotalityOfList(const std::vector<Position> &positionsTrue, Position gap)
{
    std::vector<Position> copiePositionsTrue;
    for (auto& position : positionsTrue) {
        copiePositionsTrue.push_back(addGap(position, gap));
    }
    return copiePositionsTrue;
}
/**
 * va renvoyer les positions de départ briques sur la plateau
 * @brief brickPositionToBoardPosition
 * @param positionsTrue
 * @param gap
 */
std::vector<Position> Game::brickPositionToBoardPosition(const std::vector<Position> & positionsTrue, Position gap){
    return addGapForTotalityOfList(positionsTrue, gap);
}


/**
 * verifie si les positions sont sur le plateau
 * @brief Game::inBoard
 * @param positionsInBoard
 * @return
 */
bool Game::inBoardHeight(const std::vector<Position> & positionsInBoard){
    for (auto& position : positionsInBoard) {
        if(!board.inBoardHeight(position)){
            return false;
        }
    }
    return true;
}

void Game::BoardPrefill()
{
    std::random_device rd; // Utilisé pour initialiser le générateur de nombres aléatoires
    std::mt19937 gen(rd()); // Générateur de nombres aléatoires


    int maxHeight = board.getHeight() / 2;

    while(getCurrentNbLines()< maxHeight+3){//rajout du +3 pour car il compte la brique courante et elle prend 3 ligne en general
        //donc comme ca on compte juste les lignes  apartir du bas

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
}

/**
 * verifie si une ligne continet une case non vide
 * @brief Game::isHalfFill
 * @return
 */
int Game::getCurrentNbLines() {
    int currentNbLines = 0;

    // Parcourir le plateau de bas en haut
    for (int row = board.getHeight() - 1; row >= 0; row--) {

        // Vérifier si la ligne a au moins une case rempli
        for (int col = 0; col < board.getWidth(); col++) {
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


bool Game::inBoardWidth(const std::vector<Position> & positionsInBoard){
    for (auto& position : positionsInBoard) {
        if(!board.inBoardWidth(position)){
            return false;
        }
    }
    return true;
}

/**
 * va verifier si au positions de la direction donnée dans le board qu'il n y ai pas de collisions
 * @brief Game::hasCollisions
 * @param positionsInBoard
 * @param dir
 * @return
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
    int multiplicateur = 0;
    switch (ligne){
    case 1:
        multiplicateur = 40 ;
        break ;
    case 2:
        multiplicateur = 100 ;
        break ;
    case 3:
        multiplicateur = 300 ;
        break ;
    case 4:
        multiplicateur = 1200 ;
        break ;
    default :
        break ;
    }
    return (multiplicateur * ligne + drop)* niveau ;
}

