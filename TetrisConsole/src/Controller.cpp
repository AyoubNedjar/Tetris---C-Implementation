#include "Controller.h"
#include <iostream>

using namespace std;

Controller::Controller(Game& g, View v): game(g), view(v){};


/**
 * va etre executer quand rotate , translate vont etre excuter car ils auront notifier le controller et
 * ce dernier executera la methode update
 * @brief Controller::update
 */
void Controller::update(){
    view.displayBoard(game.getBoard());
}

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
            break;

        case 'w' :
            game.drop();
            break;

        case 'e' :
             game.translate(Direction::LEFT);
            break;

        case 'r' :
            game.translate(Direction::RIGHT);
            break;

        case 't' :
            game.rotate(Rotation::ANTI_CLOCKWISE);
            break;
        }
    }while(true);

}

