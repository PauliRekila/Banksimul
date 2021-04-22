#ifndef DLLMANAGEMENT_H
#define DLLMANAGEMENT_H

#include <QObject>
#include <QTimer>
#include <QStringList>
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
    void saldoTaiTapahtumatTaiNosto();

    QString korttinumero;
    QString taulu;
    QString asiakas;
    QString tili;
    QString tilinsaldo;
    QString arvo_2;
    QString arvo_3;
    QStringList tilintapahtumat;
    QString painettunappi;

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
    void receiveKirjauduUlosFromMenu();
    void receiveRequestSaldoFromMenu();
    void receiveRequestTapahtumatFromMenu();
    void receiveRequestNostoFromMenu();
    void receiveNostaMaaraFromNosto(double);
    void receiveEiRahaaFromNosto();
    void receiveMenuTimer();
    void receiveNostaTimerFromIlmoitus();

};

#endif // DLLMANAGEMENT_H
