#include "Controller.h"
#include <iostream>

using namespace std;

Controller::Controller(Game& g, View v): game(g), view(v){};

/**
 * Ici il y aura le boucle de jeu
 * @brief Controller::start
 */
void Controller::start(){

    string userInput;
    std::cout<<"bienvenue voici le board ";
    view.displayBoard(game.getBoard());
    int i = 0;
    do{
        std::cout<<"entré d pour descendre la piece  ";
            getline(cin, userInput);

        switch(userInput[0]){
        case 'd' :
            game.translate(Direction::DOWN);
        }
        view.displayBoard(game.getBoard());
    }while(i==0);

}

