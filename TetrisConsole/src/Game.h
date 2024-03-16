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
    std::unique_ptr<Brick> currentBrick;//pointeur intelligent
    State state;
    std::vector<Position> listOfCurrentPositions;
    bool isNewBrick;


public:
    Game();
    std::vector<Position> convertStartPositionsBrickToPositionsBoard(const std::vector<Position> & positionsTrue, Position gap);
    bool inBoard(const std::vector<Position> & positionsTrue);
    Position addGap(const Position& p, Position gap);
    bool hasCollisions(const std::vector<Position> & positionsInBoard);
    std::vector<Position> posWithoutOldPos(const std::vector<Position> & newPositionsInBoard);


    void translate(Direction d);
    void rotate(Rotation sens);
    void nextShape();
    void paintStartedBrick();
    // Getters pour board, state et currentPosition
    const Board& getBoard() const { return board; }
    State getState() const { return state; }
    //informe si on est tjrs en train de jouer avec la brique courante  ou si
    //on vient de commencer a jouer avec une brique
    bool getIsNewBrick();

    // Setter pour state
    void setState(State newState) { state = newState; }

};

#endif // GAME_H
