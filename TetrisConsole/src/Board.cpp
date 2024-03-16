#include "Board.h"
#include "CommonData.h"
#include "directoryBrick/i.h"
#include "directoryBrick/j.h"
#include "directoryBrick/l.h"
#include "directoryBrick/s.h"
#include "directoryBrick/square.h"
#include "directoryBrick/t.h"
#include "directoryBrick/z.h"


/**
 * Cette methode va redimentionner le vecteur de vecteur en créant plusieurs Height vecteur qui repésente les
 * lignes et crée un vecteur interne pour chaque ligne avec width éléments.
 * @brief Board::Board
 */
Board::Board():height(20), width(10){
    board.resize(height, std::vector<CaseType>(width, CaseType::NOT_OCCUPIED));

};

std::map<const std::type_info*, CaseType> Board::brickTypeToCaseType = {
    {&typeid(I), CaseType::SHAPE_I},
    {&typeid(J), CaseType::SHAPE_J},
    {&typeid(L), CaseType::SHAPE_L},
    {&typeid(S), CaseType::SHAPE_S},
    {&typeid(Square), CaseType::SHAPE_SQUARE},
    {&typeid(T), CaseType::SHAPE_T},
    {&typeid(Z), CaseType::SHAPE_Z}
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



/**
 * verifie si un position se trouve sur le plateau
 * @brief Board::inBoard
 * @param p
 * @return
 */
bool Board::inBoard(Position p){
    return (p.getX() >= 0 && p.getX() < getHeight() && p.getY() >= 0 && p.getY() < getWidth()) ;
}

void Board::insert(Position p,  std::unique_ptr<Brick> b)
{
    //auto it  = brickTypeToCaseType.find(&typeid(*b));//je lui donne l objet pointé et il trouve les infos de ce type
    //if (it != brickTypeToCaseType.end()) {
        // Insérer la brique dans le tableau en utilisant le type de case correspondant
        //board[p.getY()][p.getX()] = CaseType::SHAPE_I;//it->second;
    board[p.getX()][p.getY()] = CaseType::SHAPE_I;
    //}
}

void Board::deleteOldBrick(Position p)
{
    board[p.getX()][p.getY()] = CaseType::NOT_OCCUPIED;
}

CaseType Board::getType(Position p)
{
    return board[p.getX()][p.getY()];
}

const int Board::getHeight() const
{
    return height;
}

const int Board::getWidth() const
{
    return width;
}

const std::vector<std::vector<CaseType> > &Board::getBoard() const
{
    return board;
}



