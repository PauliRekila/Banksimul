#ifndef DLLMANAGEMENT_H
#define DLLMANAGEMENT_H

#include <QObject>
#include "dllrestapi.h"
#include "menu.h"
//#include "enginerest.h"

class dllmanagement : public QObject
{
    Q_OBJECT
public:
    dllmanagement(QObject *parent = nullptr);
    ~dllmanagement();
private:
    engineRest *pEngineRest;
    Dllrestapi *pInterfaceRest;
    menu *pMenu;
public slots:
    void getAsiakasSlot(QNetworkReply *reply);
signals:

};

#endif // DLLMANAGEMENT_H
