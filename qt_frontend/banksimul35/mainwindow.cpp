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
    kirjauduUlos();

    connect(timer, &QTimer::timeout,
            this, QOverload<>::of(&MainWindow::lopeta));
    connect(prfid, SIGNAL(sendDataToExe(QString)),
            this, SLOT(receiveDataFromSerial(QString)));
    connect(prfid, SIGNAL(sendErrToExe()),
            this, SLOT(receiveErrFromSerial()));
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

    delete prfid;
    prfid = nullptr;

}

void MainWindow::lopeta()
{
    qDebug() << "Aika loppui";
    this->close();
    timer->stop();
}

void MainWindow::kirjauduUlos()
{
    prfid = new Dllserialport;

}


void MainWindow::on_pushButton_clicked()
{
    // pdllm->getAsiakasNimi();
    //ppindll->testDialog();
}

void MainWindow::receiveDataFromSerial(QString)
{
    delete prfid;
    prfid = nullptr;
}

void MainWindow::receiveErrFromSerial()
{
    delete prfid;
    prfid = nullptr;
    kirjauduUlos();
}
