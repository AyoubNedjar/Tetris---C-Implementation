#ifndef WINDOWSGAME_H
#define WINDOWSGAME_H

#include "TetrisBoard.h"
#include <QDialog>
#include <QMainWindow>

namespace Ui {
class WindowsGame;
}

class WindowsGame : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowsGame(QWidget *parent = nullptr);
    ~WindowsGame();

private:
    Ui::WindowsGame *ui;
    TetrisBoard *tetrisBoard;
};

#endif // WINDOWSGAME_H
