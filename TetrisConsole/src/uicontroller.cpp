#include "uicontroller.h"
#include "ui_mainwindow.h"

#include <QKeyEvent>

UiController::UiController(Game& g , MainWindow& mw) : game(g) , mainWindow(mw) {

    game.addObserver(this);
}

void UiController::update(){
    game.updateStateIfWon();
    game.updateLevel();

    mainWindow.paintEvent(mainWindow.getScene(), game.getBoard());

    mainWindow.getUi()->Score->setText(QString::number(game.getScore()));
    mainWindow.getUi()->Level->setText(QString::number(game.getLevel()));
    mainWindow.getUi()->LineCompleted->setText(QString::number(game.getBoard().getCountCompleteslines()));

    if (game.getState()==PLAYING){
        mainWindow.getUi()->Time->setText("PLAYING");
    }else if(game.getState()==LOST){
        mainWindow.getUi()->Time->setText("LOST");
    }else {
        mainWindow.getUi()->Time->setText("WON");
    }

}
void UiController::start(){
    mainWindow.show();
}

