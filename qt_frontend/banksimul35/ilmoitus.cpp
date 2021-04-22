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
    ui = nullptr;
    delete timer;
    timer = nullptr;
}

void ilmoitus::lopeta()
{
/* SULKEE ILMOITUKSEN JA LOPETTAA TIMERIN*/

    this->close();
    timer->stop();
}

void ilmoitus::lukossaIlmoitus()
{
/* AVAA ILMOITUKSEN, JOKA ILMOITTAA, ETTÄ KORTTI ON LUKOSSA, JA ALOITTAA TIMERIN */

    timer->start(10000);
    ui->label_ilmoitus->setText("Kortti on lukittu, ota yhteyttä pankkiisi");

    showFullScreen();
}

void ilmoitus::lukittuIlmoitus()
{
/* AVAA ILMOITUKSEN, JA ALOITTAA TIMERIN */

    timer->start(10000);
    ui->label_ilmoitus->setText("Liian monta yritystä, kortti lukittu");

    showFullScreen();
}

void ilmoitus::eiRahaaIlmoitus()
{
/* AVAA ILMOITUKSEN, ALOITTAA TIMERIN, SEKÄ EMITTAA SIGNAALIN*/

    timer->start(10000);
    ui->label_ilmoitus->setText("Tilillä ei ole katetta!");

    showFullScreen();
    emit nostaTimer();
}
