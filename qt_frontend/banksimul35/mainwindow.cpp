#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // pdllm = new dllmanagement;
    ppindll = new Pindll;
    //QMainWindow::showFullScreen();
}

MainWindow::~MainWindow()
{
    delete ui; 

    // delete pdllm;
    // pdllm = nullptr;

    delete ppindll;
    ppindll = nullptr;
}


void MainWindow::on_pushButton_clicked()
{
    // pdllm->getAsiakasNimi();
    ppindll->testDialog();
}
