#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "menu.h"
#include <QDialog>
#include "dllmanagement.h"
#include <QTimer>
#include <QDebug>

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
private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    // menu *pmenu;
    Pindll *ppindll;
    dllmanagement *pdllm;
    QTimer *timer;
};
#endif // MAINWINDOW_H
