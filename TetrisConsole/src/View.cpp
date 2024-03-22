#include "View.h"
#include <iostream>

using namespace std;

View::View(){};

void View::displayBoard(const Board& board){

    std::cout << std::endl;


    // Parcourir le plateau de jeu et afficher chaque case
    int rowIndex = 1;
    for (const auto& row : board.getBoard()) {

        if(rowIndex>9){
            std::cout << rowIndex << "|";
        }else{
            std::cout <<" "<< rowIndex << "|";
        }


        for (const auto& cell : row) {
            switch (cell) {
            case CaseType::NOT_OCCUPIED:
                std::cout << "  |";
                break;
            case CaseType::SHAPE_I:
                std::cout << " I|";
                break;
            case CaseType::SHAPE_J:
                std::cout << " J|";
                break;
            case CaseType::SHAPE_Z:
                std::cout << " Z|";
                break;
            case CaseType::SHAPE_L:
                std::cout << " L|";
                break;
            case CaseType::SHAPE_SQUARE:
                std::cout << " #|";
                break;
            case CaseType::SHAPE_T:
                std::cout << " T|";
                break;
            case SHAPE_S:
                std::cout << " S|";
                break;
            }
        }
        // Saut de ligne à la fin de chaque ligne du plateau
        std::cout << std::endl;
        ++rowIndex;
    }
    // Affichage des indices de colonnes
    std::cout << "  ";
    for (int col = 1; col <= board.getWidth(); ++col) {
        if(col>9){
            std::cout<< col<< " ";
        }else if(col==9){
            std::cout << " " <<col<< "  ";
        }else{
            std::cout << " " <<col<< " ";
        }
    }
    std::cout << std::endl;
    std::cout <<"-----------------------------" <<endl;

}

void View::displayInfosGame(Game &game)
{
    std::cout<<"-------------------------------"<<endl;
    cout<<"---score : "<<game.getScore()<<" | "<<" ligne : "<<game.getBoard().getLines();
}

