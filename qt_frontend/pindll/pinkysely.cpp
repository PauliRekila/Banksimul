#include "pinkysely.h"
#include "ui_pinkysely.h"


pinkysely::pinkysely(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pinkysely)
{
    ui->setupUi(this);

    timer = new QTimer(this);

    connect(timer, &QTimer::timeout,
            this, QOverload<>::of(&pinkysely::lopeta));
}

pinkysely::~pinkysely()
{
    delete ui;
}

void pinkysely::pinIkkunaEngine()
{
    ui->lineEdit_pin->clear();
    ui->label_ohje->setText("SYÖTÄ PIN-KOODI");

    timer->start(10000);

    this->exec();
    this->close();
}

void pinkysely::lopeta()
{
    qDebug() << "Aika loppui";
    this->close();
    timer->stop();
}

void pinkysely::virheIlmoitus(short yritykset)
{
    short yritysten_maara = 3 - yritykset;
    QString jaljella = QString::number(yritysten_maara);
    ui->label_ohje->setText("Väärä PIN, "+jaljella+" yritystä jäljellä");
    ui->lineEdit_pin->clear();
}

void pinkysely::on_b_ok_clicked()
{

    if (ui->lineEdit_pin->text().length() == 4)
    {
      QString pin = ui->lineEdit_pin->text();
      emit signalToInterface(pin);
      qDebug() << "tunnusluku on:" << pin;
      timer->stop();
    }
    else
    {
      ui->label_ohje->setText("Anna 4 numeroa");
      timer->start(10000);
    }

     ui->lineEdit_pin->clear();
}

void pinkysely::on_b1_clicked()
{
    ui->lineEdit_pin->insert("1");
    timer->start(10000);
}

void pinkysely::on_b2_clicked()
{
    ui->lineEdit_pin->insert("2");
    timer->start(10000);
}

void pinkysely::on_b3_clicked()
{
    ui->lineEdit_pin->insert("3");
    timer->start(10000);
}

void pinkysely::on_b4_clicked()
{
    ui->lineEdit_pin->insert("4");
    timer->start(10000);
}

void pinkysely::on_b5_clicked()
{
    ui->lineEdit_pin->insert("5");
    timer->start(10000);
}

void pinkysely::on_b6_clicked()
{
    ui->lineEdit_pin->insert("6");
    timer->start(10000);
}

void pinkysely::on_b7_clicked()
{
    ui->lineEdit_pin->insert("7");
    timer->start(10000);
}

void pinkysely::on_b8_clicked()
{
    ui->lineEdit_pin->insert("8");
    timer->start(10000);
}

void pinkysely::on_b9_clicked()
{
    ui->lineEdit_pin->insert("9");
    timer->start(10000);
}

void pinkysely::on_b_c_clicked()
{
    ui->lineEdit_pin->backspace();
    timer->start(10000);
}

void pinkysely::on_b0_clicked()
{
    ui->lineEdit_pin->insert("0");
    timer->start(10000);
}
