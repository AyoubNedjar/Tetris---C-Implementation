

#include "Game.h"

/**
 * Ici quand je crée game j'initialise le statut comme en train de jouer et je donne
 * le position de depart au milieu du plateau
 *
 * le currentBrick c'est un pointeur d une brique donc on lui donne la référence d une brique
 * @brief Game::Game
 */
Game::Game(): rules(10, 10, 10),currentBrick(&bag.nextShape()), state(State::PLAYING)
    , currentPosition(Position(0, board.getWidth()/2)){}

Game::~Game(){
    delete currentBrick;
}
void Game::translate(Direction dir){
    if(isNewBrick){
        Position inputPosition(0, board.getWidth()/2);
        std::vector<Position> listTruePositions;
        listTruePositions = currentBrick->getPositionsTrue();

        Position gap((inputPosition.getX()-listTruePositions.front().getX()),
                     (inputPosition.getY()-listTruePositions.front().getY()));


    }
}

void convertPositionsBrickToPositionsBoard(std::vector<Position> & positionsTrue, Position gap){
    for (auto& position : positionsTrue) {
        position += gap;//ajout du decalage
    }
}
