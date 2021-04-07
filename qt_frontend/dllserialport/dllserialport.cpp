#include "dllserialport.h"

Dllserialport::Dllserialport(QObject *parent) : QObject(parent)
{
    pEngine = new engine;

    connect(pEngine, SIGNAL(signalToInterface(QString)),
            this, SLOT(receiveSignalFromEngine(QString)));
}

Dllserialport::~Dllserialport()
{
    delete pEngine;
    pEngine = nullptr;
}

void Dllserialport::openReadClose()
{
    pEngine->open();
}

void Dllserialport::readPortInfo()
{
    pEngine->info();
}

void Dllserialport::receiveSignalFromEngine(QString info)
{
    emit sendInfoToExe(info);
}
