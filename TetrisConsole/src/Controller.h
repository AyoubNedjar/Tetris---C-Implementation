#ifndef CONTROLLER_H
#define CONTROLLER_H


#include "Game.h"
#include "Observer.h"
#include "View.h"
class Controller: public Observer
{
private:
    Game& game  ;
    View view;
public:
    Controller(Game& g,View v);
    void start();
    void update() override;
};

#endif // CONTROLLER_H
