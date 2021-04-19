#ifndef DLLMANAGEMENT_H
#define DLLMANAGEMENT_H

#include <QObject>
#include <QTimer>
#include "dllrestapi.h"
#include "dllserialport.h"
#include "pindll.h"
#include "menu.h"
#include "ilmoitus.h"
#include "nosto.h"
#include "saldo.h"
#include "tapahtumat.h"

class dllmanagement : public QObject
{
    Q_OBJECT
public:
    dllmanagement(QObject *parent = nullptr);
    ~dllmanagement();
    void deleteManager();
    void getTiedot(QString, QString);
    void getKortti(QString, QString);
    void getAsiakasNimi(QString);
    void pinAloitus();

    QString korttinumero;
    QString taulu;
    QString tili;
    QString arvo_1;
    QString arvo_2;
    QString arvo_3;

private:
    Dllrestapi *pDllrestapi;
    Dllserialport *pDllserialport;
    Pindll *ppindll;
    menu *pmenu;
    ilmoitus *pilmoitus;
    nosto *pnosto;
    saldo *psaldo;
    tapahtumat *ptapahtumat;

public slots:
    void receiveTiedotFromRestapi(QNetworkReply*);
    void receiveKorttiFromRestapi(QNetworkReply*);
    void receiveSignalFromPindll(QString);
    void receiveLukittuFromPindll();
    void receiveDataFromSerialport(QString);

};

#endif // DLLMANAGEMENT_H
