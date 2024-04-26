#ifndef UICONTROLLER_H
#define UICONTROLLER_H


#include "Model/Game.h"
class UiController
{
private:
    Game& game;
public:
    UiController(Game &g);
};

#endif // UICONTROLLER_H
