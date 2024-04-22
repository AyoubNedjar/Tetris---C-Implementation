#include "windowsgame.h"
#include "ui_windowsgame.h"
#include <QMainWindow>

WindowsGame::WindowsGame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowsGame)
{
    Game *gameModel = new Game();
    ui->setupUi(this);
    tetrisBoard  = new TetrisBoard(gameModel, this);
    setCentralWidget(tetrisBoard);
}

WindowsGame::~WindowsGame()
{
    delete ui;
    delete tetrisBoard;
}
