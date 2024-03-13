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

    int getHeight() const{
        return height;
    };

    // Setter pour height
    void setHeight(int newHeight){
        height = newHeight;
    };

    // Getter pour width
    int getWidth() const{
        return width;
    };

    // Setter pour width
    void setWidth(int newWidth){
         width = newWidth ;
    };

    // Getter pour board
    const std::vector<std::vector<CaseType>>& getBoard() const{
        return board;
    };
};

#endif // BOARD_H
