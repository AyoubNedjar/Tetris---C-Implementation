#ifndef UIBOARD_H
#define UIBOARD_H

#include <QWidget>
#include "Model/Board.h"
#include <QPainter>

class UiBoard : public QWidget {
    Q_OBJECT

public:
    explicit UiBoard(QWidget *parent = nullptr);
    void setBoard(const Board &board);

protected:
    void paintEvent(QPaintEvent *event)override;

private:
    Board uiBoard;
    int cellWidth;
    int cellHeight;
};


#endif // UIBOARD_H
