#ifndef PINKYSELY_H
#define PINKYSELY_H

#include <QDebug>
#include <QObject>
#include <QDialog>
#include <QLineEdit>
#include <QTimer>

namespace Ui {
class pinkysely;
}

class pinkysely : public QDialog
{
    Q_OBJECT

public:
    pinkysely(QWidget *parent = nullptr);
    ~pinkysely();
    void pinIkkunaEngine();
    void lopeta();
    void virheIlmoitus(short);
    void uloskirjautuminen();

private slots:
    void on_b1_clicked();
    void on_b2_clicked();
    void on_b3_clicked();
    void on_b4_clicked();
    void on_b5_clicked();
    void on_b6_clicked();
    void on_b7_clicked();
    void on_b8_clicked();
    void on_b9_clicked();
    void on_b_c_clicked();
    void on_b0_clicked();
    void on_b_ok_clicked();

private:
    Ui::pinkysely *ui;
    QTimer *timer;

signals:
    void signalToInterface(QString);
    void kirjaudutaanUlos();
};

#endif // PINKYSELY_H
