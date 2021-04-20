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

private slots:
    void on_b_ulos_clicked();
    void on_b_saldo_clicked();

private:
    Ui::menu *ui;
    QTimer *timer;

signals:
    void kirjauduUlos();
    void requestSaldo();
};

#endif // MENU_H
