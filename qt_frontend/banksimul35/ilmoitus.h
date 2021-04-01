#ifndef ILMOITUS_H
#define ILMOITUS_H

#include <QDialog>

namespace Ui {
class ilmoitus;
}

class ilmoitus : public QDialog
{
    Q_OBJECT

public:
    explicit ilmoitus(QWidget *parent = nullptr);
    ~ilmoitus();

private:
    Ui::ilmoitus *ui;
};

#endif // ILMOITUS_H
