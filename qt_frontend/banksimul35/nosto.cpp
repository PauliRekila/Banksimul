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
    emit menuTimer();
    qDebug() << "Aika loppui";
    this->close();
    timer->stop();
}

void nosto::nostoIkkuna(QString asiakas, QString saldo)
{
    saldomaara = saldo.toDouble();
    qDebug() << saldomaara << "saldomaara";
    ui->label_tiedot->setText(asiakas);
    ui->label_saldo->setText("Saldo: "+saldo+" €");
    timer->start(10000);
    this->exec();

}



void nosto::on_b_sulje_clicked()
{
    lopeta();
}

void nosto::on_b_20_clicked()
{
    timer->stop();
    if (saldomaara <20){
        emit eiRahaa();

    }
    else {
        emit nostaMaara(20);
        lopeta();
    }
}

void nosto::on_b_40_clicked()
{
    timer->stop();
    if (saldomaara <40){
        emit eiRahaa();

    }
    else {
        emit nostaMaara(40);
        lopeta();
    }
}

void nosto::on_b_60_clicked()
{
    timer->stop();
    if (saldomaara <60){
        emit eiRahaa();

    }
    else {
        emit nostaMaara(60);
        lopeta();
    }
}

void nosto::on_b_100_clicked()
{
    timer->stop();
    if (saldomaara <100){
        emit eiRahaa();

    }
    else {
        emit nostaMaara(100);
        lopeta();
    }
}

void nosto::on_b_200_clicked()
{
    timer->stop();
    if (saldomaara <200){
        emit eiRahaa();

    }
    else {
        emit nostaMaara(200);
        lopeta();
    }
}

void nosto::on_b_500_clicked()
{
    timer->stop();
    if (saldomaara <500){
        emit eiRahaa();

    }
    else {
        emit nostaMaara(500);
        lopeta();
    }
}
