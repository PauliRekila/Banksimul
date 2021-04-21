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
    ui->tapahtumat_text->append(tapahtumat[0]);
    ui->tapahtumat_text->append(tapahtumat[1]);
    ui->tapahtumat_text->append(tapahtumat[2]);
    ui->tapahtumat_text->append(tapahtumat[3]);
    ui->tapahtumat_text->append(tapahtumat[4]);

    timer->start(10000);

    this->exec();
    this->close();
}

void saldo::on_b_poistu_clicked()
{
    lopeta();
}
