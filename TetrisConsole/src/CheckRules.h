#ifndef CHECKRULES_H
#define CHECKRULES_H

#include "Board.h"

class CheckRules
{

private:
    int scoreMax;
    int timeMax;
    int lineMax;

public:
    CheckRules();
    CheckRules(int scoreMax, int timeMax, int linemax);
    bool isTimeOver(int currentTime);
    bool isScoreOver(int currentScore);
    bool isLineComplete(Board& board);


};

#endif // CHECKRULES_H
