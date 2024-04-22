#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "windowsgame.h"
#include <QPushButton>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    connect(ui->playButton, &QPushButton::clicked, this, &MainWindow::buttonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::buttonClicked(){
    this->hide();

    WindowsGame *secondWindow = new WindowsGame;

    secondWindow->show();
}
