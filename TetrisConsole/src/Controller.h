#ifndef CONTROLLER_H
#define CONTROLLER_H


#include "Game.h"
#include "View.h"
class Controller
{
private:
    Game game  ;
    View view;
public:
    Controller(Game g,View v);
    void start();
};

#endif // CONTROLLER_H
