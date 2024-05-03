#ifndef GAME_H
#define GAME_H

#include "Bag.h"
#include "CheckRules.h"
#include "../Observer/Observable.h"
#include "../directoryBrick/Brick.h"
#include "CommonData.h"
class Game: public Observable
{

private:
    CheckRules rules;
    Board board;
    Bag bag;
    std::unique_ptr<Brick> currentBrick;//pointeur intelligent
    State state;
    std::vector<Position> listOfCurrentPositions;
    int score;
    int level;
    time_t startTime ;
    bool canDrop;

    void makeBoard();
    void setState(State newState);

    bool applyNewPositionsWhenValid(const std::vector<Position> & newPositions);
    bool hasCollisions(const std::vector<Position> & positionsInBoard);

    std::vector<Position> addGapForBrickPositions(const std::vector<Position> & positionsTrue, Position gap);
    Position addGap(const Position& p, Position gap);
    std::vector<Position> posWithoutOldPos(const std::vector<Position> & newPositionsInBoard);

    int calculScore(int ligne , int drop , int niveau);
public:
    Game();

    int getScore();
    int getLevel()const;
    const Board& getBoard() const ;
    State getState() const ;

    std::vector<Position> brickPositionToBoardPosition(const std::vector<Position> & positionsTrue, Position gap);

    bool posIsInBoardWidth(const std::vector<Position> & positionsTrue);
    bool posIsInBoardHeight(const std::vector<Position> & positionsTrue);

    void BoardPrefill();
    int getCurrentNbLines();
    void setBoard(int height, int width);
    void updateLevel();

    int moveBrick(Direction d, bool withDrop);
    void rotate(Rotation sens);
    void drop();
    void nextShape();
    void insertBrickToBoard();
    bool isGameOver();
    void updateStateIfWon();
    void checkState();
};

#endif // GAME_H
