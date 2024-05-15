#include "uicontroller.h"
#include "ui_mainwindow.h"

#include <QKeyEvent>
#include <QTimer>
#include <QMessageBox>
UiController::UiController(Game& g , MainWindow& mw) : game(g) , mainWindow(mw) {

    game.addObserver(this);
}

void UiController::update(){
    if(game.getState()== State::PLAYING){
        game.updateStateIfWon();
        game.updateLevel();

        mainWindow.setMoveInterval(game.getSpeedLevel(game.getLevel())/60000);
        mainWindow.paintEvent(mainWindow.getScene(), game.getBoard());

        mainWindow.getUi()->Score->setText(QString::number(game.getScore()));
        mainWindow.getUi()->Level->setText(QString::number(game.getLevel()));
        mainWindow.getUi()->LineCompleted->setText(QString::number(game.getBoard().getCountCompleteslines()));
        mainWindow.getUi()->Time->setText(QString::number(game.getTimeRemaining()/60) +" : "+
                                          QString::number(game.getTimeRemaining()%60));
    }else if (game.getState() == State::LOST){
        QMessageBox messageBox;
        messageBox.setWindowTitle("You've lost");
        messageBox.setText("Thank you for playing Tetris!");
        messageBox.setIcon(QMessageBox::Information);
        messageBox.setStandardButtons(QMessageBox::Ok);

        // Display the message box
        messageBox.exec();
        mainWindow.close();
    }else {
        QMessageBox messageBox;
        messageBox.setWindowTitle("You've won");
        messageBox.setText("Thank you for playing Tetris!");
        messageBox.setIcon(QMessageBox::Information);
        messageBox.setStandardButtons(QMessageBox::Ok);

        // Display the message box
        messageBox.exec();
        mainWindow.close();
    }
}
void UiController::start(){
    mainWindow.show();
}

