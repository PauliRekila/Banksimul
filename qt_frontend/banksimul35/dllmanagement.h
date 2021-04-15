#ifndef DLLMANAGEMENT_H
#define DLLMANAGEMENT_H

#include <QObject>
#include <QTimer>
#include "dllrestapi.h"
#include "dllserialport.h"
#include "pindll.h"
#include "menu.h"

class dllmanagement : public QObject
{
    Q_OBJECT
public:
    dllmanagement(QObject *parent = nullptr);
    ~dllmanagement();
    void deleteManager();
    void getAsiakasNimi();
private:
    Dllrestapi *pDllrestapi;
    Dllserialport *pDllserialport;
    Pindll *ppindll;
    menu *pmenu;
signals:
public slots:
    void receiveSignalFromRestapi(QNetworkReply*);
    void receiveSignalFromPindll(short);

};

#endif // DLLMANAGEMENT_H
