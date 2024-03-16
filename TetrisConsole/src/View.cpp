#include "View.h"
#include <iostream>



View::View(){};

void View::displayBoard(const Board& board){

    // Parcourir le plateau de jeu et afficher chaque case
    for (const auto& row : board.getBoard()) {
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
                std::cout << " []";
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
    }



}
