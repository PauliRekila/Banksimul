#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{    
    ui->setupUi(this);
    pdllm = new dllmanagement;
    ppindll = new Pindll;    
    timer = new QTimer(this);

    connect(timer, &QTimer::timeout,
            this, QOverload<>::of(&MainWindow::lopeta));
    connect(prfid, SIGNAL(sendDataToExe(QString)),
            this, SLOT(receiveDataFromSerial(QString)));
    connect(prfid, SIGNAL(sendErrToExe()),
            this, SLOT(receiveErrFromSerial()));

    kirjauduUlos();
    showFullScreen();
}

MainWindow::~MainWindow()
{
    delete ui;
    ui = nullptr;
    delete pdllm;
    pdllm = nullptr;
    delete timer;
    timer = nullptr;
    delete ppindll;
    ppindll = nullptr;
    delete prfid;
    prfid = nullptr;

}

void MainWindow::lopeta()
{
/* SULKEE IKKUNAN JA LOPETTAA TIMERIN */

    this->close();
    timer->stop();
}

void MainWindow::kirjauduUlos()
{
/* ALUSTAA OLION, MIKÄ SUORITTAA DLLSERIALPORTIN, JOTTA SE AVAA PORTIN JA ON VALMIS LUKEMAAN UUDEN KORTIN */

    prfid = new Dllserialport;
}


void MainWindow::on_pushButton_clicked()
{
    pdllm->pinAloitus();
}

void MainWindow::receiveDataFromSerial(QString)
{
/* TUHOAA OLION, KUN KORTTI ONNISTUNEESTI LUETTU, JOTTA RFID-LUKIJA EI JATKA LUKEMISTA TAUSTALLA */

    delete prfid;
    prfid = nullptr;
}

void MainWindow::receiveErrFromSerial()
{
/* KUN TULEE LUKUVIRHE, TUHOAA OLION JA SUORITTAA KIRJAUDUULOS-FUNKTION */

    delete prfid;
    prfid = nullptr;
    kirjauduUlos();
}
