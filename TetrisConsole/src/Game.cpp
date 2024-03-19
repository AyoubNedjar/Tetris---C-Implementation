

#include "Game.h"
#include <stdexcept>

/**
 * Ici quand je crée game j'initialise le statut comme en train de jouer et je donne
 * le position de depart au milieu du plateau
 *
 * le currentBrick c'est un pointeur d une brique donc on lui donne la référence d une brique
 * @brief Game::Game
 */
Game::Game(): rules(10, 10, 10), state(State::PLAYING){

    currentBrick = bag.nextShape();
    paintStartedBrick();
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

}


void Game::translate(Direction dir){

        if(!inBoard(listOfCurrentPositions)){
            throw std::out_of_range("Position is out of board bounds");
        }


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
        if(inBoard(newPositionsAfterDirection) && !hasCollisions(posWithoutOldPos(newPositionsAfterDirection))){

           for(auto& pos : listOfCurrentPositions){
               board.deleteOldBrick(pos);
           }

           board.insert(newPositionsAfterDirection, currentBrick->getType() );

           listOfCurrentPositions = newPositionsAfterDirection;
        }else{
           //avant de passe a la brique suivante on doit mettre a jour le board
           //cad verifier si il faut supprimer les lignes remplies

           board.updateCompleteLines();

            nextShape();

        }
        notifyObservers();
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
 * retourne une position
 * @brief addGap
 */
Position Game::addGap(const Position& p, Position gap){
    return Position(p.getX()+gap.getX(), p.getY()+gap.getY());
}

/**
 * va renvoyer les positions de départ briques sur la plateau
 * @brief convertPositionsBrickToPositionsBoard
 * @param positionsTrue
 * @param gap
 */
std::vector<Position> Game::convertStartPositionsBrickToPositionsBoard(const std::vector<Position>& positionsTrue, Position gap){
    std::vector<Position> copiePositionsTrue;
    for (auto& position : positionsTrue) {
        copiePositionsTrue.push_back(addGap(position, gap));
    }
    return copiePositionsTrue;
}

/**
 * verifie si les positions sont sur le plateau
 * @brief Game::inBoard
 * @param positionsInBoard
 * @return
 */
bool Game::inBoard(const std::vector<Position> & positionsInBoard){
    for (auto& position : positionsInBoard) {
        if(!board.inBoard(position)){
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













