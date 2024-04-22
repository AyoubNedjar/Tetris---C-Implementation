#ifndef TETRISBOARD_H
#define TETRISBOARD_H

#include "Model/Game.h"
#include "qlabel.h"
#include <QWidget>
class TetrisBoard  : public QWidget {

    Q_OBJECT

public:
    TetrisBoard(Game *game, QWidget *parent = nullptr);

private:
    Game *game;
    QVector<QVector<QLabel*>> cellGrid;
};

#endif // TETRISBOARD_H
