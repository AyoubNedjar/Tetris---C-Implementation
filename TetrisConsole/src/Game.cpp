

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

    listOfCurrentPositions = currentBrick->getPositionsTrue();
    Position inputPosition(0, board.getWidth()/2);
    Position gap((inputPosition.getX()-listOfCurrentPositions.front().getX()),
                 (inputPosition.getY()-listOfCurrentPositions.front().getY()));

    listOfCurrentPositions = convertStartPositionsBrickToPositionsBoard(listOfCurrentPositions, gap);

    for(auto& p :listOfCurrentPositions){

        board.insert(p, std::move(currentBrick));
    }
}

/**
 *
 * va dessiner la forme au tout debut du tableau
 * @brief Game::paintStartedBrick
 */
void Game::paintStartedBrick(){

    Position inputPosition(0, board.getWidth()/2);
    Position gap((inputPosition.getX()-listOfCurrentPositions.front().getX()),
                 (inputPosition.getY()-listOfCurrentPositions.front().getY()));

    listOfCurrentPositions = convertStartPositionsBrickToPositionsBoard(listOfCurrentPositions, gap);

    for(auto& p :listOfCurrentPositions){

        board.insert(p, std::move(currentBrick));

    }
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
   listOfCurrentPositions = currentBrick->getPositionsTrue();
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

        if(!inBoard(newPositionsAfterDirection)){
           throw std::out_of_range("Position is out of board bounds");
        }
        if(!hasCollisions(newPositionsAfterDirection)){//
           for(auto& pos : newPositionsAfterDirection){
               board.insert(pos, std::move(currentBrick));
           }

           listOfCurrentPositions = newPositionsAfterDirection;
        }else{
           //si il y a collision on change de piece
            nextShape();

        }

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













