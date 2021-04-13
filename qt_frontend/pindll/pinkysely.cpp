#include "pinkysely.h"
#include "ui_pinkysely.h"
#include "pindll.h"


pinkysely::pinkysely(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pinkysely)
{
    ui->setupUi(this);

    timer = new QTimer(this);

    connect(timer, &QTimer::timeout,
            this, QOverload<>::of(&pinkysely::lopeta));

    //ppindll = new Pindll;
}

pinkysely::~pinkysely()
{
    delete ui;

    //delete ppindll;
    //ppindll = nullptr;
}

void pinkysely::testiDialogi2()
{
    ui->lineEdit_pin->clear();
    ui->label_ohje->setText("SYÖTÄ PIN-KOODI");

    timer->start(10000);

    this->exec();
    this->show();
    this->close();
}

void pinkysely::lopeta()
{
    qDebug() << "Aika loppui";
    this->close();
    timer->stop();
}

void pinkysely::on_b_ok_clicked()
{

    if (ui->lineEdit_pin->text().length() == 4)
    {
      Pindll *ppindll;
      ppindll = new Pindll;
      short tunnusluku = ui->lineEdit_pin->text().toInt();
      ppindll->kirjautuminen(tunnusluku);
      qDebug() << "tunnusluku on:" << tunnusluku;
      delete ppindll;
      ppindll = nullptr;
    }
    else
    {
      ui->label_ohje->setText("Anna 4 numeroa");
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
