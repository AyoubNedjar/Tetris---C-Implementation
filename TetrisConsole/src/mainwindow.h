#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <string>

#include "qgraphicsscene.h"
#include "Model/Game.h"

namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Game * game = nullptr , QWidget *parent = nullptr);
    ~MainWindow();

    Ui::MainWindow *getUi();
    QGraphicsScene *getScene();

    void paintEvent(QGraphicsScene *scene , const Board &board)const;
    Game *getGame();
    void keyReleaseEvent(QKeyEvent *event);

    void setMoveInterval(int newInterval);
private slots:

    void on_SubmitPersoSize_clicked();
    void on_SubmitSize_clicked();
    void on_SubmitPrefill_clicked();

    void on_ButtonStart_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene _scene;

    Game& game ;

    void makeInvisibleTab();
    void setNameForTab();

    QTimer* timer;

    int MOVE_INTERVAL; // Time interval for moving the brick down in milliseconds
    void moveBrickDown();
    std::string makeTimeInMin();

};

#endif // MAINWINDOW_H

