#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _scene(this)
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
    ui->tabWidget->setTabVisible(1,false);
    ui->tabWidget->setTabVisible(2,false);
    ui->tabWidget->setTabVisible(3,false);

    QRect viewContentsRect = ui->TetrisBoard->contentsRect();
    _scene.setSceneRect(viewContentsRect);
    ui->TetrisBoard->setScene(&_scene);

    _scene.addRect(10,10,25, 25);
    _scene.addRect(10,35,25,25);
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

        heightBoard = 20 ;
        widthBoard = 10 ;

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

        if (height >= 10 && height <= 30 &&
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
