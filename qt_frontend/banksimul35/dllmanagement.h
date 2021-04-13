#ifndef DLLMANAGEMENT_H
#define DLLMANAGEMENT_H

#include <QObject>
#include "dllrestapi.h"
#include "pindll.h"
#include "menu.h"
#include "dllserialport.h"

class dllmanagement : public QObject
{
    Q_OBJECT
public:
    dllmanagement(QObject *parent = nullptr);
    ~dllmanagement();
    void getAsiakasNimi();
private:
    Dllrestapi *pDllrestapi;
    Pindll *ppindll;
    menu *pmenu;
    Dllserialport *pserialport;

signals:
public slots:
    void receiveSignalFromRestapi(QNetworkReply*);
    void receiveSignalFromPindll(short);
    void receiveSignalFromRFID(QString);

};

#endif // DLLMANAGEMENT_H
