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
    timer = new QTimer(this);

    connect(timer, &QTimer::timeout,
            this, QOverload<>::of(&MainWindow::lopeta));
}

MainWindow::~MainWindow()
{
    delete ui; 

    // delete pdllm;
    // pdllm = nullptr;
    delete timer;
    timer = nullptr;

    delete ppindll;
    ppindll = nullptr;
}

void MainWindow::lopeta()
{
    qDebug() << "Aika loppui";
    this->close();
    timer->stop();
}


void MainWindow::on_pushButton_clicked()
{
    // pdllm->getAsiakasNimi();
    ppindll->testDialog();
}
