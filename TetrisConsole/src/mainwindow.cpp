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

//PAGE 1
void MainWindow::on_pushButton_clicked()
{
    if (ui->checkBoxYes->checkState()){
        ui->textEdit_2->setText("Hello yes");

        ui->tabWidget->setTabVisible(0,false);
    }
    if (ui->checkBoxNo->checkState()) {
        ui->textEdit_2->setText("Hello no");

        ui->tabWidget->setTabVisible(0,false);
        ui->tabWidget->setTabVisible(1,false);

        heightBoard = 20 ;
        widthBoard = 10 ;
    }
}

//PAGE 2
void MainWindow::on_SubmitButton_clicked()
{

    QString heightStr = ui->HeightBoard->text().trimmed(); // Remove leading and trailing whitespace
    QString widthStr = ui->WidthBoard->text().trimmed();

    if (heightStr.isEmpty() || widthStr.isEmpty()){
        ui->textEdit_2->setText("Input cannot be empty");
    }else {
        int height = ui->HeightBoard->text().toInt();
        int width = ui->WidthBoard->text().toInt();

        if (height >= 10 && height <= 30 &&
            width  >= 10 && width  <= 30 ){
            ui->textEdit_2->setText("Wshh tes bon");

            heightBoard = height ;
            widthBoard = width ;
        }else {
            ui->textEdit_2->setText("Wshh tes nuls");
        }
    }
}

