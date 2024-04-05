#ifndef CHECKRULES_H
#define CHECKRULES_H

#include "Board.h"

class CheckRules
{

private:
    int scoreMax;
    int timeMax;
    int lineMax;
    int levelMax;

public:
    CheckRules();
    CheckRules(int scoreMax, int timeMax, int linemax , int levelMax);
    bool isTimeOver(int currentTime);
    bool isScoreOver(int currentScore);
    bool isLineComplete(Board& board);
    bool isLevelOver(int currentLevel);

};

#endif // CHECKRULES_H
