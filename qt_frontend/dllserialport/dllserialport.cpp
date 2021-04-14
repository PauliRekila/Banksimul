#include "dllserialport.h"

Dllserialport::Dllserialport(QObject *parent) : QObject(parent)
{
    pEngine = new engine;
    connect(pEngine, SIGNAL(signalToInterface(QString)),
            this, SLOT(receiveSignalFromEngine(QString)));
    connect(pEngine, SIGNAL(errToInterface()),
            this, SLOT(receiveErrFromEngine()));
    qDebug() << "interface luotu";
}

Dllserialport::~Dllserialport()
{
    delete pEngine;
    pEngine = nullptr;
}


void Dllserialport::receiveSignalFromEngine(QString data)
{
    emit sendDataToExe(data);
}

void Dllserialport::receiveErrFromEngine()
{
    emit sendErrToExe();
}
