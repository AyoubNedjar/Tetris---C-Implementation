    #ifndef UICONTROLLER_H
#define UICONTROLLER_H

#include <QMainWindow>

#include "Model/Game.h"
#include "Observer/Observer.h"
#include "mainwindow.h"

class UiController :public Observer
{
public:
    UiController(Game &game , MainWindow& mw);

    void update() override;
    void start();
    void moveBrickDown();

private:
    MainWindow& mainWindow ;
    Game& game  ;
};


#endif // UICONTROLLER_H
