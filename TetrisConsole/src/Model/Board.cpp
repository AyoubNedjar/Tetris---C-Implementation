#include "Board.h"
#include "CommonData.h"

Board::Board():height(20), width(10){
    countCompletesLines = 9;
    board.resize(height, std::vector<CaseType>(width, CaseType::NOT_OCCUPIED));

};

Board::Board(int height,int width):height(height), width(width){
    countCompletesLines = 9;
    board.resize(height, std::vector<CaseType>(width, CaseType::NOT_OCCUPIED));
};

const int Board::getCountCompleteslines() const{
    return countCompletesLines ;
}

bool Board::posIsInBoardHeight(Position p){
    return (p.getX() >= 0 && p.getX() < getHeight()) ;
}
bool Board::posIsInBoardWidth(Position p){
    return (p.getY() >= 0 && p.getY() < getWidth()) ;
}

std::vector<int> Board::getIndexCompleteLines()
{
    std::vector<int> completeLines;
    int cpt  = 0;
    int lineNumber = 0;
    for(auto& row : board){
        for(auto& cell : row){
            if(cell != CaseType::NOT_OCCUPIED){
                cpt++;
            }
        }
        if(cpt==row.size()){
            completeLines.push_back(lineNumber);
        }
        cpt=0;
        lineNumber++;
    }

    countCompletesLines += completeLines.size();
    return completeLines;
}

void Board::removeCompletesLines(const std::vector<int> & linesList)
{
    for (int line : linesList) {
        for (int i = line; i > 0; --i) {
            board[i] = board[i - 1];
        }
        board[0] = std::vector<CaseType>(getWidth(), CaseType::NOT_OCCUPIED);//replace the top line with NOT_OCCUPIED TYPE
    }

}

int Board::updateCompleteLines()
{
    std::vector<int> lineToRemove = getIndexCompleteLines();
    removeCompletesLines(lineToRemove);
    return lineToRemove.size();
}

void Board::insert(const std::vector<Position> & listPositions, CaseType type)
{
    for (auto& p : listPositions) {
        board[p.getX()][p.getY()] = type;
    }
}

void Board::deleteOldBrick(Position p)
{
    board[p.getX()][p.getY()] = CaseType::NOT_OCCUPIED;
}

const CaseType &Board::operator()(int row, int col) const
{
    return board[row][col];
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

const std::vector<std::vector<CaseType>> &Board::getBoard() const
{
    return board;
}
/*
 * Used for tests .
 */
void Board::setTypeAtPos(Position pos , CaseType type){
    board[pos.getX()][pos.getY()] = type ;
}


