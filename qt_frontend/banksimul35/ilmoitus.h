#ifndef ILMOITUS_H
#define ILMOITUS_H

#include <QDialog>
#include <QTimer>
#include <QDebug>

namespace Ui {
class ilmoitus;
}

class ilmoitus : public QDialog
{
    Q_OBJECT

public:
    ilmoitus(QWidget *parent = nullptr);
    ~ilmoitus();
    void lopeta();
    void lukossaIlmoitus();
    void lukittuIlmoitus();
    void eiRahaaIlmoitus();

private:
    QTimer *timer;
    Ui::ilmoitus *ui;

signals:
    void nostaTimer();
};

#endif // ILMOITUS_H
