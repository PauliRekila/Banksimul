#ifndef DLLMANAGEMENT_H
#define DLLMANAGEMENT_H

#include <QObject>
#include "engineRest.h"
#include "dllrestapi.h"
#include "menu.h"


class dllmanagement : public QObject
{
    Q_OBJECT
public:
    dllmanagement(QObject *parent = nullptr);
private:
    menu *pmenu;
    engineRest *pEngineRest;
private slots:
    void getAsiakasSlot();
    void receiveSignalFromDll();

signals:

};

#endif // DLLMANAGEMENT_H
