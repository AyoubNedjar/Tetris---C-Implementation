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
    Brick* currentBrick;//pointeur de brique sinon erreur car instance de brique classe abstraite non autorisée
    State state;
    Position currentPosition;
    bool isNewBrick;

    void convertPositionsBrickToPositionsBoard(std::vector<Position> & positionsTrue, Position gap);


public:
    Game();
    ~Game();
    void translate(Direction d);
    void rotate(Rotation sens);

    // Getters pour board, state et currentPosition
    const Board& getBoard() const { return board; }
    State getState() const { return state; }
    Position getCurrentPosition() const { return currentPosition; }
    //informe si on est tjrs en train de jouer avec la brique courante  ou si
    //on vient de commencer a jouer avec une brique
    bool getIsNewBrick();

    // Setter pour state
    void setState(State newState) { state = newState; }

};

#endif // GAME_H
