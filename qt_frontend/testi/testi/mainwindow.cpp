#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pdllrest = new Dllrestapi;
    connect(pdllrest, SIGNAL(sendSignalToExe(QString)),
            this, SLOT(receiveSignalFromInterface(QString)));

}

MainWindow::~MainWindow()
{
    delete ui;
    delete pdllrest;
    pdllrest = nullptr;
}

void MainWindow::receiveSignalFromInterface(QString info)
{
    ui->label->setText(info);
    qDebug() << "kirjoitettu signaali labeliin";
}


void MainWindow::on_pushButton_clicked()
{
    pdllrest->sendTiedot("toimiiko");
    qDebug() << "dll lähetetty funktio";

}
