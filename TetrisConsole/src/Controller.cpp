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
    view.displayCommand();
}

/**
 * Ici il y aura le boucle de jeu
 * @brief Controller::start
 */
void Controller::start(){
    string userInputCommand;


    std::string userInputChoiceSizeBoard ;
    std::cout<<"Do you want to play with the regular size of the board ? y(es) - n(o)?" << std::endl;
    do {
        std::cin >> userInputChoiceSizeBoard ;
    }while (userInputChoiceSizeBoard[0] != 'y' && userInputChoiceSizeBoard[0] != 'n');
    if(userInputChoiceSizeBoard[0] == 'n'){
        makeBoardForUser();
    }

     //demande si on doit preremplir le board

    std::string userInputChoicePopulateOrNot ;
    std::cout<<"Do you want prepopulate the board ? y(es) - n(o)?" << std::endl;
    do {
        std::cin >> userInputChoicePopulateOrNot ;
    }while (userInputChoicePopulateOrNot[0] != 'y' && userInputChoicePopulateOrNot[0] != 'n');
    if(userInputChoicePopulateOrNot[0] == 'y'){
        game.BoardPrefill();
    }


    view.displayMessage("bienvenue voici le board");
    view.displayBoard(game.getBoard());
    view.displayCommand();
    int i = 0;
    while (game.getState()==State::PLAYING && cin>>userInputCommand ){
        switch(userInputCommand[0]){
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

void Controller::makeBoardForUser()
{
    int height , width ;
    std::string userInput ;
    std::cout << "Please enter a height for your board ." << std::endl ;
    std::cout << "(minimum -> 10 , maximum -> 50)" << std::endl;
    do {
        std::cin >> userInput ;
    }while (stoi(userInput) < 10 || stoi(userInput) > 50);
    height = stoi(userInput);

    std::cout << "Please enter a width for your board ." << std::endl ;
    std::cout << "(minimum -> 10 , maximum -> 50)" << std::endl;
    do {
        std::cin >> userInput ;
    }while (stoi(userInput) < 10 || stoi(userInput) > 50);
    width = stoi(userInput);
    game.setBoard(height, width);
}

