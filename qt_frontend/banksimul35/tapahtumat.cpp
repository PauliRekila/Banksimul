#include "tapahtumat.h"
#include "ui_tapahtumat.h"

tapahtumat::tapahtumat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tapahtumat)
{
    ui->setupUi(this);
    timer = new QTimer(this);

    connect(timer, &QTimer::timeout,
            this, QOverload<>::of(&tapahtumat::lopeta));
}

tapahtumat::~tapahtumat()
{
    delete ui;
    delete timer;
    timer = nullptr;
}

void tapahtumat::lopeta()
{
    qDebug() << "Aika loppui";
    this->close();
    timer->stop();
}
