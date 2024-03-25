#include "Game.h"
#include <ostream>
#include <stdexcept>

/**
 * Ici quand je crée game j'initialise le statut comme en train de jouer et je donne
 * le position de depart au milieu du plateau
 *
 * le currentBrick c'est un pointeur d une brique donc on lui donne la référence d une brique
 * @brief Game::Game
 */
Game::Game(): rules(3, 10, 3), state(State::PLAYING){

    canDrop = true;
    currentBrick = bag.nextShape();
    paintStartedBrick();
    score = 0 ;
    niveau = 0;
    nbLigneComplete = 0;

}



/**
 *
 * va dessiner la forme au tout debut du tableau
 * @brief Game::paintStartedBrick
 */
void Game::paintStartedBrick(){

    listOfCurrentPositions = currentBrick->getPositionsTrue();
    Position inputPosition(0, board.getWidth()/2);
    Position gap((inputPosition.getX()-listOfCurrentPositions.front().getX()),
                 (inputPosition.getY()-listOfCurrentPositions.front().getY()));

    listOfCurrentPositions = convertStartPositionsBrickToPositionsBoard(listOfCurrentPositions, gap);

    board.insert(listOfCurrentPositions, currentBrick->getType());

}

bool Game::isGameOver()
{
    return (state==State::LOST);
}

void Game::updateStateIfVictory()
{
    if(rules.isLineComplete(board) || rules.isScoreOver(score)){
        state = State::LOST;
    }
}

/**
 * va checker si on respecte toujours les regles de jeu pour mettre a jour l'état de jeu
 * @brief Game::checkState
 */
void Game::checkState()
{
    //we don't use the methode for the time in this poject in console mode
    if(rules.isLineComplete(board) || rules.isScoreOver(score)){
        setState(State::LOST);
    }

}
int * Game::getNiveau(){
    return &niveau ;
}

int Game::getScore()
{
    return score;
}
int Game::getNbLigneComplete(){
    return nbLigneComplete;
}
/**
 * va récupérer un nouvelle brique du sac pour la mettre brique courante
 * @brief Game::nextShape
 */
void Game::nextShape(){
    listOfCurrentPositions.clear();
    std::unique_ptr<Brick> nextBrickPtr = bag.nextShape();

    //tranfert de propriété avec pointeur intelligent pour que current brique pointe vers la prochaine
    currentBrick = std::move(nextBrickPtr);
    paintStartedBrick();
    canDrop = false;
}


void Game::translateWithDropOrNot(Direction dir, bool WithDrop){

    /*if(!inBoard(listOfCurrentPositions)){
            throw std::out_of_range("Position is out of board bounds");
        }*/


    //j aurais pu eviter de créer une nouveles liste et et voir si il est dans le board et si il y  des collisions dans
    //mais je ne connaitrai pas la raison du pq je ne peux pas bouger
    //on copie
    Position p;
    Position delta = p.getPositionFromDirection(dir);
    std::vector<Position> newPositionsAfterDirection;

    for(auto& p1 :listOfCurrentPositions){

        newPositionsAfterDirection.push_back(addGap(p1, delta));

    }

    /*
         *si les procaines positions se trouventd dans le board et que il n y a pas de collisions aux prochaines nouvelles positions
         *alors on peut les placer sinon on passe a la prochaine brique
         */
    bool isInBoardAndNotHaveCollisions = applyTransformationAndCheckForValidPositions(newPositionsAfterDirection);

    if(!isInBoardAndNotHaveCollisions){
        if(dir==Direction::RIGHT || dir==Direction::LEFT){
            board.updateCompleteLines();
        }else{
            board.updateCompleteLines();
            score += calculScore(1, 0 , niveau);
            nextShape();
        }
    }


    if(!WithDrop){
        notifyObservers();
    }

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

    newPositionsAfterRotate = convertPositionsInBoardForRotate(rotatePositionsInBrick, gapBetweenPosCurrentAndPosInBrick);
    applyTransformationAndCheckForValidPositions(newPositionsAfterRotate);
    notifyObservers();
}

void Game::drop()
{
    char cptDropCase = 0;
    while(canDrop){
        translateWithDropOrNot(Direction::DOWN, true);
        cptDropCase++;
    }
    canDrop = true;//candrop sert a savoir si on passe a une autre shape, donc tant que on passe pas a une autre shape
    //on va boucler, et quand on arrivera tt en bas alors on pourra afficher le board car on mettre candrop = false, et ca bouclera plus
    notifyObservers();
}

bool Game::applyTransformationAndCheckForValidPositions(const std::vector<Position> &newPositions)
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
 * @brief convertPositionsBrickToPositionsBoard
 * @param positionsTrue
 * @param gap
 */
std::vector<Position> Game::convertStartPositionsBrickToPositionsBoard(const std::vector<Position>& positionsTrue, Position gap){
    return addGapForTotalityOfList(positionsTrue, gap);
}

std::vector<Position> Game::convertPositionsInBoardForRotate(const std::vector<Position> &positionsTrue, Position gap)
{
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
    }
    return (multiplicateur * ligne + drop)* niveau ;
}

