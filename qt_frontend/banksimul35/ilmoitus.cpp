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

void ilmoitus::lukossaIlmoitus()
{
    timer->start(10000);
    ui->label_ilmoitus->setText("Kortti on lukittu, ota yhteyttä pankkiisi");

    this->exec();    
}

void ilmoitus::lukittuIlmoitus()
{
    timer->start(10000);
    ui->label_ilmoitus->setText("Liian monta yritystä, kortti lukittu");

    this->exec();
}

void ilmoitus::eiRahaaIlmoitus()
{
    timer->start(10000);
    ui->label_ilmoitus->setText("Tilillä ei ole katetta!");

    this->exec();
    emit nostaTimer();
}
