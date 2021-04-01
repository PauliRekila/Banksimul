#include "ilmoitus.h"
#include "ui_ilmoitus.h"

ilmoitus::ilmoitus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ilmoitus)
{
    ui->setupUi(this);
}

ilmoitus::~ilmoitus()
{
    delete ui;
}
