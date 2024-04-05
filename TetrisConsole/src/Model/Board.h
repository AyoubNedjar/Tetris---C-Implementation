#ifndef BOARD_H
#define BOARD_H

#include "CommonData.h"
#include <vector>
#include "Position.h"
class Board
{
private :
    int height;
    int width;
    std::vector<std::vector<CaseType>> board;
    int countCompletesLines;

    std::vector<int> getIndexCompleteLines();
    void removeCompletesLines(const std::vector<int> &linesList);

public:
    Board();
    Board(int height, int width);

    bool posIsInBoardHeight(Position pos);
    bool posIsInBoardWidth(Position p);
    const int getCountCompleteslines() const;

    int updateCompleteLines();

    void insert(const std::vector<Position> & listOfPositions , CaseType type);
    void deleteOldBrick(Position p);

    const CaseType& operator()(int row, int col) const;
    CaseType getType(Position p);
    const int getHeight() const;;
    const int getWidth() const;
    const std::vector<std::vector<CaseType>>& getBoard() const;

    void setHeight(int newHeight);;
    void setWidth(int newWidth);;

    void setTypeAtPos(Position pos , CaseType type);
};

#endif // BOARD_H
