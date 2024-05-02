#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qgraphicsscene.h"
#include <QMainWindow>
#include "Model/Game.h"
//#include "Observer/Observer.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow //, public Observer
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int getHeightBoard();
    int getWidthBoard();
    bool isPrefilled();

private slots:

    void on_SubmitPersoSize_clicked();
    void on_SubmitSize_clicked();
    void on_SubmitPrefill_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene _scene;

    Game game ;

    void makeInvisibleTab();
    void setNameForTab();

    void paintEvent(QGraphicsScene *scene , const Board &board)const;
    //void keyReleaseEvent(QKeyEvent *event);
};

#endif // MAINWINDOW_H

