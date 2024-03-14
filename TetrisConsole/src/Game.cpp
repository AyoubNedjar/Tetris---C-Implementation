

#include "Game.h"

/**
 * Ici quand je crée game j'initialise le statut comme en train de jouer et je donne
 * le position de depart au milieu du plateau
 * @brief Game::Game
 */
Game::Game(): rules(10, 10, 10), state(State::PLAYING), currentPosition(Position(0, board.getWidth()/2)){}
