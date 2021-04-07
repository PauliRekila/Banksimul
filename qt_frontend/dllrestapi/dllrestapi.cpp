#include "dllrestapi.h"

Dllrestapi::Dllrestapi(QObject *parent) : QObject(parent)
{
    pEngineRest = new engineRest;
    connect(pEngineRest, SIGNAL(sendSignalToInterface(QString)),
             this, SLOT(receiveSignalFromEngine(QString)));
}

Dllrestapi::~Dllrestapi()
{
    delete pEngineRest;
    pEngineRest = nullptr;
}

void Dllrestapi::receiveSignalFromEngine(QString info)
{
    emit sendInfoToExe(info);
}



