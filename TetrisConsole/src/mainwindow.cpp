#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _scene(this)
{
    ui->setupUi(this);

    /*QRect viewContentsRect = ui->myGraphicsView->contentsRect();
    _scene.setSceneRect(viewContentsRect);
    ui->myGraphicsView->setScene(&_scene);

    _scene.addRect(10,10,25, 25);*/
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked(bool checked)
{
    if (ui->checkBox->checkState()){
        ui->textEdit_2->setText("Hello yes");
        ui->tabWidget->setTabText(1 , "Hello");
    }
    if (ui->checkBox_2->checkState()) {
        ui->textEdit_2->setText("Hello no");
    }
    ui->tabWidget->setTabVisible(0,false);
}

