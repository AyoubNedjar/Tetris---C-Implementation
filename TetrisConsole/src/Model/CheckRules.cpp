#include <time.h>
#include "CheckRules.h"
/**
 * donne des valeurs par defaut pour faire
 * @brief CheckRules::CheckRules
 */
CheckRules::CheckRules(){}

CheckRules::CheckRules(int score, int time, int line , int level):
    scoreMax(score), timeMax(time),lineMax(line),levelMax(level){}

bool CheckRules::isScoreOver(int currentScore){
    return (currentScore > scoreMax);
}

bool CheckRules::isLineComplete(Board& board){
    return (board.getCountCompleteslines() >= lineMax);
}
bool CheckRules::isLevelOver(int currentLevel){
    return (currentLevel >= levelMax);
}
bool CheckRules::isTimeOver(time_t startTime){
    time_t endTime =  startTime + timeMax;
    return (time(NULL) < endTime);
}
int CheckRules::getTimeMax(){
    return timeMax;
}
;
