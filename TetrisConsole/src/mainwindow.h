#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qgraphicsscene.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene _scene;
};

#endif // MAINWINDOW_H
