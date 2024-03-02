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
public:
    Board();
    Board(int height, int width);
    bool contains(Position pos);
    std::vector<int> getCompleteLines();//va retourner les lines completes
    void removeCompletesLines(std::vector<int> linesList);//va supprimer les lignes complete, ce qui
    //veut dire de faire un decallage des brique en glissant tt les blacks du dessus vers le bas
};

#endif // BOARD_H
