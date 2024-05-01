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

    int heightBoard ;
    int widthBoard;
    bool prefilled ;
};

#endif // MAINWINDOW_H

