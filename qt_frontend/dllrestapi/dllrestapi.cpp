#include "dllrestapi.h"

Dllrestapi::Dllrestapi(QObject *parent) : QObject(parent)
{
    penginerest = new enginerest;

    connect(penginerest, SIGNAL(sendTiedotToInterface(QNetworkReply*)),
            this, SLOT(receiveTiedotFromEngine(QNetworkReply*)));

    connect(penginerest, SIGNAL(sendKorttiToInterface(QNetworkReply*)),
            this, SLOT(receiveKorttiFromEngine(QNetworkReply*)));
}

Dllrestapi::~Dllrestapi()
{
   delete penginerest;
    penginerest = nullptr;
}

void Dllrestapi::sendTiedot(QString taulu, QString id)
{
    penginerest->tiedot(taulu, id);
    qDebug() << taulu << id;
}

void Dllrestapi::sendKortti(QString korttinumero, QString pin)
{
    penginerest->kirjautuminen(korttinumero, pin);
}

void Dllrestapi::deleteManager()
{
    penginerest->manager->deleteLater();
}

void Dllrestapi::receiveKorttiFromEngine(QNetworkReply* reply)
{
    emit sendKorttiToExe(reply);
}

void Dllrestapi::receiveTiedotFromEngine(QNetworkReply* reply)
{
    emit sendTiedotToExe(reply);
}
