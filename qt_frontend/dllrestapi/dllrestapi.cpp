#include "dllrestapi.h"

Dllrestapi::Dllrestapi(QObject *parent) : QObject(parent)
{
    penginerest = new enginerest;
    connect(penginerest, SIGNAL(sendSignalToInterface(QString)),
            this, SLOT(receiveSignalFromEngine(QString)));
}

Dllrestapi::~Dllrestapi()
{
   delete penginerest;
    penginerest = nullptr;
}

void Dllrestapi::sendTiedot(QString info)
{
    penginerest->tiedot(info);
    qDebug() << "exestä vastaanotettu funktio";
}

void Dllrestapi::receiveSignalFromEngine(QNetworkReply* reply)
{
    emit sendSignalToExe(reply);
    qDebug() << "interfacesta lähetetty signaali";
    qDebug() << reply;
}
