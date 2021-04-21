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
    timer->stop();
    this->close();
}

void saldo::saldoIkkuna(QString asiakas, QString saldo, QStringList tapahtumat)
{
    ui->tapahtumat_text->clear();
    ui->label_nimi->setText(asiakas);
    ui->label_saldo->setText("Saldo: "+saldo+" €");
    if (tapahtumat.size() < 5){
        for (int i = 0; i < tapahtumat.size(); ++i){
            ui->tapahtumat_text->append(tapahtumat[i]);
    }
    }
    else {
        for (int i = 0; i < 5; ++i){
            ui->tapahtumat_text->append(tapahtumat[i]);
    }}
    timer->start(10000);

    this->exec();

}

void saldo::on_b_poistu_clicked()
{
    lopeta();
}
