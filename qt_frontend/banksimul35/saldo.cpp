#include "saldo.h"
#include "ui_saldo.h"

saldo::saldo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::saldo)
{
    ui->setupUi(this);
    timer = new QTimer(this);

    connect(timer, &QTimer::timeout,
            this, QOverload<>::of(&saldo::lopeta));
}

saldo::~saldo()
{
    delete ui;
    delete timer;
    timer = nullptr;
}

void saldo::lopeta()
{
    qDebug() << "Aika loppui";
    this->close();
    timer->stop();
}
