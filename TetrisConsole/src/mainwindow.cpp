#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsRectItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setNameForTab();
    makeInvisibleTab();

    QRect viewContentsRect = ui->TetrisBoard->contentsRect();
    _scene.setSceneRect(viewContentsRect);
    ui->TetrisBoard->setScene(&_scene);
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

        game.setBoard(10 ,20 );

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

            game.setBoard(height , width);

            ui->tabWidget->setTabVisible(1,false);
            ui->tabWidget->setTabVisible(2, true);
        }
    }
}

//PAGE 3
void MainWindow::on_SubmitPrefill_clicked()
{
    if(ui->checkBoxPrefillYes->checkState()){
        game.BoardPrefill();

        ui->tabWidget->setTabVisible(2,false);
        ui->tabWidget->setTabVisible(3,true);

        paintEvent(&_scene , game.getBoard());
    }
    if(ui->CheckBoxPrefillNo->checkState()){

        ui->tabWidget->setTabVisible(2,false);
        ui->tabWidget->setTabVisible(3,true);

        paintEvent(&_scene , game.getBoard());
    }
}

void MainWindow::makeInvisibleTab(){
    ui->tabWidget->setTabVisible(0,true);
    ui->tabWidget->setTabVisible(1,false);
    ui->tabWidget->setTabVisible(2,false);
    ui->tabWidget->setTabVisible(3,false);

}

void MainWindow::setNameForTab(){
    ui->tabWidget->setTabText(0,"");
    ui->tabWidget->setTabText(1,"Board size");
    ui->tabWidget->setTabText(2,"Board prefilled");
    ui->tabWidget->setTabText(3,"Game");
}
void MainWindow::paintEvent(QGraphicsScene *scene , const Board &board) const {


    int boardHeight = board.getHeight();
    int boardWidth = board.getWidth();

    int cellWidth = ui->TetrisBoard->size().width()/boardWidth;
    int cellHeight= ui->TetrisBoard->size().height()/boardHeight;

    for (int row = 0; row < board.getHeight(); ++row) {
        for (int col = 0; col < board.getWidth(); ++col) {
            QGraphicsRectItem  *rect = scene->addRect(col * cellWidth, row * cellHeight, cellWidth, cellHeight);
            // Determine the color based on the cell type
            QColor color;
            switch (board(row, col)) {
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
            rect->setBrush(color);

        }
    }
    /*void MainWindow::keyReleaseEvent(QKeyEvent *event)
    {
        switch (event->key()) {
        case Qt::Key_Left:
            _game.move(Direction::LEFT);
            break;
        case Qt::Key_Right:
            _game.move(Direction::RIGHT);
            break;
        case Qt::Key_Down:
            _game.move(Direction::DOWN);
            break;
        case Qt::Key_Up:
            _game.rotateCurrentBrick(RotationClock::CLOCKWISE);
            break;
        case Qt::Key_H:
            commandHelp();
        default:
            break;
        }

    }*/
}
