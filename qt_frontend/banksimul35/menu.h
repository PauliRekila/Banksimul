#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include <QDebug>
#include <QTimer>

namespace Ui {
class menu;
}

class menu : public QDialog
{
    Q_OBJECT

public:
    menu(QWidget *parent = nullptr);
    ~menu();
    void tervetuloaAsiakas(QString);
    void lopeta();
    QTimer *timer;

private slots:
    void on_b_ulos_clicked();
    void on_b_saldo_clicked();
    void on_b_tilitapahtumia_clicked();
    void on_b_nosta_clicked();

private:
    Ui::menu *ui;

signals:
    void kirjauduUlos();
    void requestSaldo();
    void requestTapahtumat();
    void requestNosto();
};

#endif // MENU_H
