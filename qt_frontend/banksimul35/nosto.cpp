#include "nosto.h"
#include "ui_nosto.h"

nosto::nosto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nosto)
{
    ui->setupUi(this);
    timer = new QTimer(this);

    connect(timer, &QTimer::timeout,
            this, QOverload<>::of(&nosto::lopeta));
}

nosto::~nosto()
{
    delete ui;
    delete timer;
    timer = nullptr;
}

void nosto::lopeta()
{
    qDebug() << "Aika loppui";
    this->close();
    timer->stop();
}
