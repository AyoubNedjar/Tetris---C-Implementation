#include "Board.h"



/**
 * Cette methode va redimentionner le vecteur de vecteur en créant plusieurs Height vecteur qui repésente les
 * lignes et crée un vecteur interne pour chaque ligne avec width éléments.
 * @brief Board::Board
 */
Board::Board():height(20), width(10){
    board.resize(height, std::vector<CaseType>(width, CaseType::NOT_OCCUPIED));
};

/**
 * Meme chose que le consturcteur du ha
 * @brief Board::Board
 * @param height
 * @param width
 */
Board::Board(int height,int width):height(height), width(width){
    board.resize(height, std::vector<CaseType>(width, CaseType::NOT_OCCUPIED));
};



