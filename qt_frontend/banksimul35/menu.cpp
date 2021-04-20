#include "menu.h"
#include "ui_menu.h"

menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
    timer = new QTimer(this);

    connect(timer, &QTimer::timeout,
            this, QOverload<>::of(&menu::lopeta));
}

menu::~menu()
{
    delete ui;
    delete timer;
    timer = nullptr;
}

void menu::tervetuloaAsiakas(QString asiakas)
{   
    ui->label_menu->setText("Tervetuloa, " + asiakas);

    timer->start(30000);

    this->exec();
    this->close();
}

void menu::lopeta()
{
    qDebug() << "Aika loppui";
    emit kirjauduUlos();
    this->close();
    timer->stop();
}

void menu::on_b_ulos_clicked()
{
    lopeta();
}

void menu::on_b_saldo_clicked()
{
    emit requestSaldo();
    timer->start(30000);
}
