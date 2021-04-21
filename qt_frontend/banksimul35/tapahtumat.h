#ifndef TAPAHTUMAT_H
#define TAPAHTUMAT_H

#include <QDialog>
#include <QTimer>
#include <QDebug>

namespace Ui {
class tapahtumat;
}

class tapahtumat : public QDialog
{
    Q_OBJECT

public:
    tapahtumat(QWidget *parent = nullptr);
    ~tapahtumat();
    void lopeta();
    void tapahtumatIkkuna(QString, QString, QStringList);
    unsigned int sivu = 0;
    int sivu2;
    QStringList selaustapahtumat;

private slots:
    void on_b_sulje_clicked();

    void on_b_seuraava_clicked();

    void on_b_edellinen_clicked();

private:
    Ui::tapahtumat *ui;
    QTimer *timer;
signals:
    void menuTimer();
};

#endif // TAPAHTUMAT_H
