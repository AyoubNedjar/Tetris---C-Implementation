#include "Controller.h"
#include <iostream>

Controller::Controller(Game& g, View v): game(g), view(v){};

/**
 * Ici il y aura le boucle de jeu
 * @brief Controller::start
 */
void Controller::start(){

    char userInput;
    std::cout<<"bienvenue voici le board ";
    view.displayBoard(game.getBoard());

    std::cout<<"entré d pour descendre la piece  ";
    std::cin >> userInput;

    switch(userInput){
    case 'd' :
        game.translate(Direction::DOWN);
    }
    view.displayBoard(game.getBoard());

}

