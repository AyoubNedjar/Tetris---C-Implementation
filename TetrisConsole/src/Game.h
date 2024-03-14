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

    // Getters pour board, state et currentPosition
    const Board& getBoard() const { return board; }
    State getState() const { return state; }
    Position getCurrentPosition() const { return currentPosition; }

    // Setter pour state
    void setState(State newState) { state = newState; }

};

#endif // GAME_H
