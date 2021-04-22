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
    ui = nullptr;
    delete timer;
    timer = nullptr;
}

void saldo::lopeta()
{
    emit menuTimer();
    timer->stop();
    this->close();
}

void saldo::saldoIkkuna(QString asiakas, QString saldo, QStringList tapahtumat)
{
/* KIRJOITETAAN KÄYTTÄJÄN NIMI JA SALDO */

    ui->tapahtumat_text->clear();
    ui->label_nimi->setText(asiakas);
    ui->label_saldo->setText("Saldo: "+saldo+" €");

/* VERRATAAN LISTAN KOKOA. JOS SE ON ALLE 5, NÄYTETÄÄN KAIKKI TAPAHTUMAT. MUUSSA TAPAUKSISSA NÄYTETÄÄN VAIN 5 */

    if (tapahtumat.size() < 5)
    {
        for (int i = 0; i < tapahtumat.size(); ++i)
        {
            ui->tapahtumat_text->append(tapahtumat[i]);
        }
    }

    else
    {
        for (int i = 0; i < 5; ++i)
        {
            ui->tapahtumat_text->append(tapahtumat[i]);
        }
    }

    timer->start(10000);

    showFullScreen();
}

void saldo::on_b_poistu_clicked()
{
    lopeta();
}
