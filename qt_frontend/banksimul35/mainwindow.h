#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDebug>
#include <QDialog>
#include "menu.h"
#include "dllmanagement.h"
#include "dllserialport.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void lopeta();
    void kirjauduUlos();

private slots:
    void on_pushButton_clicked();

public slots:
    void receiveDataFromSerial(QString);
    void receiveErrFromSerial();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    menu *pmenu;
    Pindll *ppindll;
    dllmanagement *pdllm;  
    Dllserialport *prfid;

};
#endif // MAINWINDOW_H
