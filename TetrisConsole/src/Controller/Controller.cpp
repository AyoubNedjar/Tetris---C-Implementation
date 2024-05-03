#include "Controller.h"
#include <iostream>

using namespace std;

Controller::Controller(Game& g, View v): game(g), view(v){};


/**
 * This method will be executed once the user try to rotate , move the brick .
 * @brief Controller::update
 */
void Controller::update(){
    game.updateStateIfWon();
    view.displayBoard(game.getBoard());
    view.displayInfosGame(game);
    view.displayCommand();
}

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


    view.displayMessage("Welcome");
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
        if (game.getBoard().getCountCompleteslines()>=10){
            *(game.getLevel()) = (game.getBoard().getCountCompleteslines()/10)+1 ;
        }
    }

    view.displayState(game);
}

void Controller::makeBoardForUser()
{
    int height , width ;
    std::string userInput ;
    std::cout << "Please enter a height for your board ." << std::endl ;
    std::cout << "(minimum -> 10 , maximum -> 20)" << std::endl;
    bool isInputValid= false;
    do {
        try{
            std::cin >> userInput ;
            if (stoi(userInput) >= 10 && stoi(userInput) <= 50){
                isInputValid = true;
            }
        }catch(invalid_argument e){
            cout<< "Invalid input! Please put a number between 10-50" << endl;
        }
    }while (!isInputValid); // if the input is valid the loop will stop
    isInputValid = false ;
    height = stoi(userInput);

    std::cout << "Please enter a width for your board ." << std::endl ;
    std::cout << "(minimum -> 10 , maximum -> 50)" << std::endl;
    do {
        try{
            std::cin >> userInput ;
            if (stoi(userInput) >= 10 && stoi(userInput) <= 50){
                isInputValid = true;
            }
        }catch(invalid_argument e){
            cout<< "Invalid input! Please put a number between 10-50" << endl;
        }
    }while (!isInputValid);
    width = stoi(userInput);
    game.setBoard(height, width);
}

