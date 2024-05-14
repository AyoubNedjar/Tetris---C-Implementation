#include "TetrisBoard.h"
#include "qlabel.h"
#include <QGridLayout>

TetrisBoard::TetrisBoard(Game *game, QWidget *parent)
    : QWidget(parent), game(game)
{
    //initialisation du plateau
    QGridLayout *layout = new QGridLayout(this);

    // Création de la grille de QLabel
    for (int i = 0; i < game->getBoard().getHeight(); ++i) {
        QVector<QLabel*> row;
        for (int j = 0; j < game->getBoard().getHeight(); ++j) {
            QLabel *cell = new QLabel(this);
            cell->setFixedSize(20, 20); // Taille de chaque cellule
            cell->setFrameStyle(QFrame::Panel | QFrame::Sunken);
            cell->setAlignment(Qt::AlignCenter);
            layout->addWidget(cell, i, j);
            row.append(cell);
        }
        cellGrid.append(row);
    }

    setLayout(layout);
}
