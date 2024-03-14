#include "Controller.h"
#include <iostream>

Controller::Controller(Game g, View v): game(g), view(v){};

/**
 * Ici il y aura le boucle de jeu
 * @brief Controller::start
 */
void Controller::start(){

    char userInput;
    std::cin >> userInput;

    switch(userInput){
    case 'd' :
        game.translate(Direction::DOWN);
    }
}
