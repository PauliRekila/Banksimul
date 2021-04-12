#include "pinkysely.h"
#include "ui_pinkysely.h"
#include "pindll.h"


pinkysely::pinkysely(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pinkysely)
{
    ui->setupUi(this);
}

pinkysely::~pinkysely()
{
    delete ui;
}

void pinkysely::on_b1_clicked()
{
    ui->lineEdit_pin->insert("1");
}

void pinkysely::on_b2_clicked()
{
    ui->lineEdit_pin->insert("2");
}

void pinkysely::on_b3_clicked()
{
    ui->lineEdit_pin->insert("3");
}

void pinkysely::on_b4_clicked()
{
    ui->lineEdit_pin->insert("4");
}

void pinkysely::on_b5_clicked()
{
    ui->lineEdit_pin->insert("5");
}

void pinkysely::on_b6_clicked()
{
    ui->lineEdit_pin->insert("6");
}

void pinkysely::on_b7_clicked()
{
    ui->lineEdit_pin->insert("7");
}

void pinkysely::on_b8_clicked()
{
    ui->lineEdit_pin->insert("8");
}

void pinkysely::on_b9_clicked()
{
    ui->lineEdit_pin->insert("9");
}

void pinkysely::on_b_c_clicked()
{
    ui->lineEdit_pin->backspace();
}

void pinkysely::on_b0_clicked()
{
    ui->lineEdit_pin->insert("0");
}

void pinkysely::on_b_ok_clicked()
{

    if (ui->lineEdit_pin->text().length() == 4)
    {
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
}
