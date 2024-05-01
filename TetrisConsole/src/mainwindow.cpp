#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "uiboard.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*
     * Set the name for the different tab.
     */
    ui->tabWidget->setTabText(0,"Board personnalisation");
    ui->tabWidget->setTabText(1,"Board size");
    ui->tabWidget->setTabText(2,"Board prefilled");
    ui->tabWidget->setTabText(3,"");

    /*
     * Make table invisible.
     */
    ui->tabWidget->setTabVisible(0,false);
    ui->tabWidget->setTabVisible(1,false);
    ui->tabWidget->setTabVisible(2,false);
    ui->tabWidget->setTabVisible(3,true);

    QRect viewContentsRect = ui->TetrisBoard->contentsRect();
    _scene.setSceneRect(viewContentsRect);
    ui->TetrisBoard->setScene(&_scene);

    /*
     * Not exactly working (not centering the board).
     */
    int cellSize = 20 ;

    heightBoard = 15;
    widthBoard = 10;

    ui->TetrisBoard->resize(cellSize* widthBoard , cellSize* heightBoard);
    for (int row = 0; row < heightBoard ; ++row) {
        for (int col = 0; col < widthBoard; ++col) {
            _scene.addRect(col*20 , row * 20, cellSize, cellSize);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

//PAGE 1
void MainWindow::on_SubmitPersoSize_clicked()
{
    if (ui->checkBoxPersoSizeYes->checkState()){
        ui->tabWidget->setTabVisible(0,false);

        //ui->TetrisBoard->resize(20*widthBoard ,20*widthBoard);
        ui->tabWidget->setTabVisible(2 , true);
    }
    if (ui->checkBoxPersoSizeNo->checkState()) {
        ui->tabWidget->setTabVisible(0,false);
        ui->tabWidget->setTabVisible(1,true);

    }
}

//PAGE 2
void MainWindow::on_SubmitSize_clicked()
{
    QString heightStr = ui->HeightBoard->text().trimmed(); // Remove leading and trailing whitespace
    QString widthStr = ui->WidthBoard->text().trimmed();

    if (!heightStr.isEmpty() && !widthStr.isEmpty()){
        int height = ui->HeightBoard->text().toInt();
        int width = ui->WidthBoard->text().toInt();

        if (height >= 10 && height <= 25 &&
            width  >= 10 && width  <= 30 ){

            heightBoard = height ;
            widthBoard = width ;

            ui->tabWidget->setTabVisible(1,false);
            ui->tabWidget->setTabVisible(2, true);
        }
    }
}

//PAGE 3
void MainWindow::on_SubmitPrefill_clicked()
{
    if(ui->checkBoxPrefillYes->checkState()){
        prefilled = true ;

        ui->tabWidget->setTabVisible(2,false);
        ui->tabWidget->setTabVisible(3,true);
    }
    if(ui->CheckBoxPrefillNo->checkState()){
        prefilled = false ;

        ui->tabWidget->setTabVisible(2,false);
        ui->tabWidget->setTabVisible(3,true);
    }
}
int MainWindow::getHeightBoard(){
    return heightBoard;
}
int MainWindow::getWidthBoard(){
    return widthBoard;
}
bool MainWindow::isPrefilled(){
    return prefilled ;
}
