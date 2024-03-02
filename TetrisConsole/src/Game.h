#ifndef GAME_H
#define GAME_H


#include "Bag.h"
#include "CheckRules.h"
#include "directoryBrick/Brick.h"
#include "CommonData.h"
class Game
{

private:
    CheckRules rules;
    Board board;
    Bag bag;
    Brick currentBrick;
    State state;
    Position currentPosition;


public:
    Game();

};

#endif // GAME_H
