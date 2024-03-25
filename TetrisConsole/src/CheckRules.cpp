
#include "CheckRules.h"
/**
 * donne des valeurs par defaut pour faire
 * @brief CheckRules::CheckRules
 */
CheckRules::CheckRules(){}

CheckRules::CheckRules(int scoreMax, int timeMax, int lineMax):
    scoreMax(scoreMax), timeMax(timeMax),lineMax(lineMax){}

bool CheckRules::isScoreOver(int currentScore)
{
    return (currentScore>scoreMax);
}

bool CheckRules::isLineComplete(Board &board)
{
    return (board.getCountCompleteslines()==lineMax);
};
