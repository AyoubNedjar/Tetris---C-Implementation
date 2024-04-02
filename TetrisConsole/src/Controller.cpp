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
    game.updateStateIfWon();
    view.displayBoard(game.getBoard());
    view.displayInfosGame(game);
}

/**
 * Ici il y aura le boucle de jeu
 * @brief Controller::start
 */
void Controller::start(){
    string userInput;
    //char userInput;
    /*view.displayMessage("Voulez-vous modifier la taille du board ? y-n");
    do {
        cin >> userInput ;
    }while(userInput[0] != 'y' && userInput[0] != 'n');
*/
    view.displayMessage("bienvenue voici le board");
    view.displayBoard(game.getBoard());
    int i = 0;
    while (game.getState()==State::PLAYING && cin>>userInput ){
        switch(userInput[0]){
        case 's' :
            game.moveBrick(Direction::DOWN, false);
            break;
        case 'q' :
            game.moveBrick(Direction::LEFT, false);
            break;
        case 'd' :
            game.moveBrick(Direction::RIGHT, false);
            break;
        case 'e' :
            game.rotate(Rotation::CLOCKWISE);
            break;
        case 'a' :
            game.rotate(Rotation::ANTI_CLOCKWISE);
            break;
        case 'w' :
            game.drop();
            break ;
        }
        if (game.getNbLigneComplete()>=10){
            *(game.getNiveau()) = (game.getNbLigneComplete()/10)+1 ;
        }
    }

    view.displayState(game);
}

