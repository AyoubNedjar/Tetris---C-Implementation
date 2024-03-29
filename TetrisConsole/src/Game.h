#ifndef GAME_H
#define GAME_H

#include "Bag.h"
#include "CheckRules.h"
#include "Observable.h"
#include "directoryBrick/Brick.h"
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
    int niveau;
    int TotalLigneComplete;
    bool canDrop;



public:
    Game();

    int getScore();
    int *getNiveau();
    int getNbLigneComplete();
    const Board& getBoard() const ;
    State getState() const ;

    std::vector<Position> brickPositionToBoardPosition(const std::vector<Position> & positionsTrue, Position gap);

    std::vector<Position> addGapForTotalityOfList(const std::vector<Position> & positionsTrue, Position gap);
    bool applyNewPositionsWhenValid(const std::vector<Position> & newPositions);
    Position addGap(const Position& p, Position gap);
    bool hasCollisions(const std::vector<Position> & positionsInBoard);
    std::vector<Position> posWithoutOldPos(const std::vector<Position> & newPositionsInBoard);

    bool inBoardWidth(const std::vector<Position> & positionsTrue);
    bool inBoardHeight(const std::vector<Position> & positionsTrue);

    int moveBrick(Direction d, bool withDrop);
    void rotate(Rotation sens);
    void drop();
    void nextShape();
    void insertBrickToBoard();
    bool isGameOver();
    void updateStateIfVictory();
    void checkState();

    void setState(State newState) { state = newState; }
    int calculScore(int ligne , int drop , int niveau);
private :

};

#endif // GAME_H
