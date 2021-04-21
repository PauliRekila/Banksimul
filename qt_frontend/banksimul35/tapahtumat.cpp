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
    delete timer;
    timer = nullptr;
}

void tapahtumat::lopeta()
{
    qDebug() << "Aika loppui";
    this->close();
    timer->stop();
}

void tapahtumat::tapahtumatIkkuna(QString asiakas, QString saldo, QStringList tapahtumat)
{
    selaustapahtumat = tapahtumat;
    sivu2 = sivu +10;
    ui->tapahtumat_text->clear();
    ui->label_nimi->setText(asiakas);
    ui->label_saldo->setText("Saldo: "+saldo+" €");
    if (selaustapahtumat.size() < sivu2){
        for (int i = 0; i < selaustapahtumat.size(); ++i){
            ui->tapahtumat_text->append(selaustapahtumat[i]);
    }
    }
    else {
        for (int i = 0; i < 10; ++i){
            ui->tapahtumat_text->append(selaustapahtumat[i]);
    }}
    timer->start(10000);

    this->exec();

}

void tapahtumat::on_b_sulje_clicked()
{
    lopeta();
}

void tapahtumat::on_b_seuraava_clicked()
{
    timer->start(10000);
    if (selaustapahtumat.size() > sivu2){
    sivu = sivu + 10;
    sivu2 = sivu +10;
    ui->tapahtumat_text->clear();
    if (selaustapahtumat.size() < sivu2){
        for (int i = sivu; i < selaustapahtumat.size(); ++i){
            ui->tapahtumat_text->append(selaustapahtumat[i]);
    }
    }
        else {
        for (int i = sivu; i < sivu2; ++i){
            ui->tapahtumat_text->append(selaustapahtumat[i]);
    }}}
}

void tapahtumat::on_b_edellinen_clicked()
{
    timer->start(10000);
    if (sivu > 0){
    sivu = sivu - 10;
    sivu2 = sivu +10;
    ui->tapahtumat_text->clear();
    if (selaustapahtumat.size() < sivu2){
        for (int i = sivu; i < selaustapahtumat.size(); ++i){
            ui->tapahtumat_text->append(selaustapahtumat[i]);
    }
    }
    else {
        for (int i = sivu; i < sivu2; ++i){
            ui->tapahtumat_text->append(selaustapahtumat[i]);
    }
    }
    }
}
