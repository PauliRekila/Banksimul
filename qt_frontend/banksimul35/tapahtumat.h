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

private:
    Ui::tapahtumat *ui;
    QTimer *timer;
};

#endif // TAPAHTUMAT_H
