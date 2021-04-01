#ifndef TAPAHTUMAT_H
#define TAPAHTUMAT_H

#include <QDialog>

namespace Ui {
class tapahtumat;
}

class tapahtumat : public QDialog
{
    Q_OBJECT

public:
    explicit tapahtumat(QWidget *parent = nullptr);
    ~tapahtumat();

private:
    Ui::tapahtumat *ui;
};

#endif // TAPAHTUMAT_H
