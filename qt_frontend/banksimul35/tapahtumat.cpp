#include "tapahtumat.h"
#include "ui_tapahtumat.h"

tapahtumat::tapahtumat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tapahtumat)
{
    ui->setupUi(this);
    timer = new QTimer(this);

    connect(timer, &QTimer::timeout,
            this, QOverload<>::of(&tapahtumat::lopeta));
}

tapahtumat::~tapahtumat()
{
    delete ui;
    ui = nullptr;
    delete timer;
    timer = nullptr;
}

void tapahtumat::lopeta()
{
    emit menuTimer();
    this->close();
    timer->stop();
}

void tapahtumat::tapahtumatIkkuna(QString asiakas, QString saldo, QStringList tapahtumat)
{
/*
   TALLENNETAAN TAPAHTUMAT SELAUSTAPAHTUMAT-LISTAAN JA MÄÄRITELLÄÄN SIVU2-MUUTTUJA
   TARKISTETAAN LISTAN KOKO. JOS LISTAN KOKO ON ALLE 10 NÄYTETÄÄN KAIKKI TAPAHTUMAT.
   MUUSSA TAPAUKSISSA NÄYTETÄÄN VAIN 10 ENSIMMÄISTÄ TAPAHTUMAA
*/

    selaustapahtumat = tapahtumat;
    sivu2 = sivu +10;

    ui->tapahtumat_text->clear();
    ui->label_nimi->setText(asiakas);
    ui->label_saldo->setText("Saldo: "+saldo+" €");

    if (selaustapahtumat.size() < sivu2)
    {
        for (int i = 0; i < selaustapahtumat.size(); ++i)
        {
            ui->tapahtumat_text->append(selaustapahtumat[i]);
        }
    }

    else
    {
        for (int i = 0; i < 10; ++i)
        {
            ui->tapahtumat_text->append(selaustapahtumat[i]);
        }
    }

    timer->start(10000);

    showFullScreen();

}

void tapahtumat::on_b_sulje_clicked()
{
    lopeta();
}

void tapahtumat::on_b_seuraava_clicked()
{
/*
   JOS SELAUSTAPAHTUMIEN KOKO ON ISOMPI KUIN MUUTTUJA SIVU2, LISÄTÄÄN 10 MUUTTUJAAN SIVU JA MÄÄRITELLÄÄN SIVU2 UUDESTAAN.
   NÄYTETÄÄN TAPAHTUMAT ALKAEN LISTAN JÄSENESTÄ, JOKA ON YHTÄSUURI KUIN MUUTTUJAN SIVU ARVO.
   JOS SELAUSTAPAHTUMIEN KOKO ON PIENEMPI KUIN SIVU2, NÄYTETÄÄN KAIKKI TAPAHTUMAT. MUISSA TAPAUKSISSA
   NÄYTETÄÄN VAIN 10 TAPAHTUMAA
*/

    timer->start(10000);

    if (selaustapahtumat.size() > sivu2)
    {
        sivu = sivu + 10;
        sivu2 = sivu + 10;

        ui->tapahtumat_text->clear();

        if (selaustapahtumat.size() < sivu2)
        {
            for (int i = sivu; i < selaustapahtumat.size(); ++i)
            {
                ui->tapahtumat_text->append(selaustapahtumat[i]);
            }
        }
        else
        {
            for (int i = sivu; i < sivu2; ++i)
            {
                ui->tapahtumat_text->append(selaustapahtumat[i]);
            }
        }
    }
}

void tapahtumat::on_b_edellinen_clicked()
{
/*
   JOS MUUTTUJA SIVU ON SUUREMPI KUIN 0, VÄHENNETÄÄN 10 MUUTTUJASTA SIVU JA MÄÄRITELLÄÄN SIVU2 UUDESTAAN.
   NÄYTETÄÄN TAPAHTUMAT ALKAEN LISTAN JÄSENESTÄ, JOKA ON YHTÄSUURI KUIN MUUTTUJAN SIVU ARVO.
   JOS SELAUSTAPAHTUMIEN KOKO ON PIENEMPI KUIN SIVU2, NÄYTETÄÄN KAIKKI TAPAHTUMAT. MUISSA TAPAUKSISSA
   NÄYTETÄÄN VAIN 10 TAPAHTUMAA
*/

    timer->start(10000);

    if (sivu > 0)
    {
        sivu = sivu - 10;
        sivu2 = sivu + 10;

        ui->tapahtumat_text->clear();

        if (selaustapahtumat.size() < sivu2)
        {
            for (int i = sivu; i < selaustapahtumat.size(); ++i)
            {
                ui->tapahtumat_text->append(selaustapahtumat[i]);
            }
        }
        else
        {
            for (int i = sivu; i < sivu2; ++i)
            {
                ui->tapahtumat_text->append(selaustapahtumat[i]);
            }
        }
    }
}
