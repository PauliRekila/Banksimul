#ifndef DLLMANAGEMENT_H
#define DLLMANAGEMENT_H

#include <QObject>
#include "dllrestapi.h"
#include "menu.h"

class dllmanagement : public QObject
{
    Q_OBJECT
public:
    dllmanagement(QObject *parent = nullptr);
    ~dllmanagement();
    QString asiakas;
    void getAsiakasNimi();
private:
    Dllrestapi *pDllrestapi;
    menu *pmenu;
signals:
public slots:
    void receiveSignalFromRestapi(QNetworkReply*);

};

#endif // DLLMANAGEMENT_H
