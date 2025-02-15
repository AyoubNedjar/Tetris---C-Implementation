#ifndef CONTROLLER_H
#define CONTROLLER_H


#include "../Model/Game.h"
#include "../Observer/Observer.h"
#include "../View/View.h"
class Controller: public Observer
{
private:
    Game& game  ;
    View view;
public:
    Controller(Game& g,View v);
    void start();
    void makeBoardForUser();
    void update() override;
};

#endif // CONTROLLER_H
