#include "View/View.h"
#include "Controller/Controller.h"
#include "mainwindow.h"
#include "qapplication.h"
#include "uicontroller.h"

using namespace std;

// int main()
// {
//     Game g;
//     View v;
//     Controller c(g, v);

//     g.addObserver(&c);

//     c.start();

//     return 0;
// }

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Game game;
    MainWindow mw(&game) ;
    UiController uc(game , mw);
    uc.start();
    return app.exec();
}
