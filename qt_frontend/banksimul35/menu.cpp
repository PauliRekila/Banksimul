#include "menu.h"
#include "ui_menu.h"

menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}

void menu::tervetuloaAsiakas(QString asiakas)
{
    ui->label_menu->setText("Tervetuloa, "+asiakas);
}
