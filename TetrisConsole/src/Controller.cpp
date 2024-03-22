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


    view.displayInfosGame(game);
    view.displayBoard(game.getBoard());

}

/**
 * Ici il y aura le boucle de jeu
 * @brief Controller::start
 */
void Controller::start(){

   // string userInput;
    char userInput;
    std::cout<<"bienvenue voici le board ";
    view.displayBoard(game.getBoard());
    int i = 0;
    do{
        std::cout<<"entré d pour descendre la piece  ";
            //getline(cin, userInput);

        switch(userInput){
        case 'd' :
            game.translateWithDropOrNot(Direction::DOWN, false);
            break;

        case 'w' :
            game.drop();
            break;

        case 'e' :
            game.translateWithDropOrNot(Direction::LEFT, false);
            break;

        case 'r' :
            game.translateWithDropOrNot(Direction::RIGHT, false);
            break;

        case 't' :
            game.rotate(Rotation::ANTI_CLOCKWISE);
            break;
        }
    }while(cin>>userInput);

}

