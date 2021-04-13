#ifndef SALDO_H
#define SALDO_H

#include <QDialog>
#include <QTimer>
#include <QDebug>

namespace Ui {
class saldo;
}

class saldo : public QDialog
{
    Q_OBJECT

public:
    saldo(QWidget *parent = nullptr);
    ~saldo();
    void lopeta();

private:
    Ui::saldo *ui;
    QTimer *timer;
};

#endif // SALDO_H
