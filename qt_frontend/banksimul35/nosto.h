#ifndef NOSTO_H
#define NOSTO_H

#include <QDialog>
#include <QTimer>
#include <QDebug>

namespace Ui {
class nosto;
}

class nosto : public QDialog
{
    Q_OBJECT

public:
    nosto(QWidget *parent = nullptr);
    ~nosto();
    void lopeta();
    void nostoIkkuna(QString, QString);
    double saldomaara;
    QTimer *timer;

private slots:
    void on_b_sulje_clicked();

    void on_b_20_clicked();

    void on_b_40_clicked();

    void on_b_60_clicked();

    void on_b_100_clicked();

    void on_b_200_clicked();

    void on_b_500_clicked();

private:
    Ui::nosto *ui;

signals:
    void nostaMaara(double);
    void eiRahaa();
    void menuTimer();

};

#endif // NOSTO_H
