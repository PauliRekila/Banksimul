#include "ilmoitus.h"
#include "ui_ilmoitus.h"

ilmoitus::ilmoitus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ilmoitus)
{
    ui->setupUi(this);
    timer = new QTimer(this);

    connect(timer, &QTimer::timeout,
            this, QOverload<>::of(&ilmoitus::lopeta));
}

ilmoitus::~ilmoitus()
{
    delete ui;
    delete timer;
    timer = nullptr;
}

void ilmoitus::lopeta()
{
    qDebug() << "Aika loppui";
    this->close();
    timer->stop();
}
