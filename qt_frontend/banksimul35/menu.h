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
private:
    Ui::menu *ui;
    QTimer *timer;
};

#endif // MENU_H
