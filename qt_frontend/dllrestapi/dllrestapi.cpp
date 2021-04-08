#include "dllrestapi.h"

Dllrestapi::Dllrestapi(QObject *parent) : QObject(parent)
{
    pEngineRest = new engineRest;
    connect(pEngineRest, SIGNAL(sendToInterface(QNetworkReply*)),
            this, SLOT(receiveSignalFromEngine(QNetworkReply*)));
}

Dllrestapi::~Dllrestapi()
{
    delete pEngineRest;
    pEngineRest = nullptr;
}

void Dllrestapi::receiveSignalFromEngine(QNetworkReply* info)
{
    emit sendToExe(info);
}
