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
    void getTiedot(QString, QString);
    void getKortti(QString, QString);
    void pinAloitus();
    QString korttinumero;

private:
    Dllrestapi *pDllrestapi;
    Dllserialport *pDllserialport;
    Pindll *ppindll;
    menu *pmenu;
public slots:
    void receiveTiedotFromRestapi(QNetworkReply*);
    void receiveKorttiFromRestapi(QNetworkReply*);
    void receiveSignalFromPindll(QString);
    void receiveDataFromSerialport(QString);

};

#endif // DLLMANAGEMENT_H
