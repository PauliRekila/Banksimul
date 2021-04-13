#ifndef DLLMANAGEMENT_H
#define DLLMANAGEMENT_H

#include <QObject>
#include "dllrestapi.h"
#include "pindll.h"
#include "menu.h"

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
signals:
public slots:
    void receiveSignalFromRestapi(QNetworkReply*);
    void receiveSignalFromPindll(short);

};

#endif // DLLMANAGEMENT_H
