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
    explicit ilmoitus(QWidget *parent = nullptr);
    ~ilmoitus();
    void lopeta();

private:
    QTimer *timer;
    Ui::ilmoitus *ui;
};

#endif // ILMOITUS_H
