#ifndef VIEW_H
#define VIEW_H



#include "Game.h"
class View
{
public:
    View();
    void displayBoard(const Board& board);
    void displayInfosGame(Game& game);

};

#endif // VIEW_H
