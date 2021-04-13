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

private:
    Ui::nosto *ui;
    QTimer *timer;

};

#endif // NOSTO_H
