/*#include "uiboard.h"

UiBoard::UiBoard(QWidget *parent) : QWidget(parent) {}

/*void UiBoard::setBoard(const Board &board){
    uiBoard = board ;
    update();
}
void UiBoard::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    for (int row = 0; row < uiBoard.getHeight(); ++row) {
        for (int col = 0; col < uiBoard.getWidth(); ++col) {
            QRect rect(col * cellWidth, row * cellHeight, cellWidth, cellHeight);
            // Determine the color based on the cell type
            QColor color;
            switch (uiBoard(row, col)) {
            case CaseType::NOT_OCCUPIED:
                color = Qt::white;
                break;
            case CaseType::SHAPE_I:
                color = Qt::black;
                break;
            case CaseType::SHAPE_J:
                color = Qt::blue;
                break ;
            case CaseType::SHAPE_L:
                color = Qt::red;
                break;
            case CaseType::SHAPE_S:
                color = Qt::yellow;
                break;
            case CaseType::SHAPE_SQUARE:
                color = Qt::green;
                break;
            case CaseType::SHAPE_T:
                color = Qt::cyan;
                break ;
            case CaseType::SHAPE_Z:
                color = Qt::gray;
                break;
            }
            // Fill the rectangle with the determined color
            painter.fillRect(rect, color);
            // Optionally, draw borders or other decorations
            painter.drawRect(rect);
        }
    }
*/

