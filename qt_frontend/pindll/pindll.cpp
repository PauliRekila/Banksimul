#include "pindll.h"

Pindll::Pindll(QObject *parent) : QObject(parent)
{
    ppinkysely = new pinkysely;

    connect(ppinkysely, SIGNAL(signalToInterface(QString)),
            this, SLOT(receiveSignalFromEngine(QString)));
}

Pindll::~Pindll()
{
    delete ppinkysely;
    ppinkysely = nullptr;
}

void Pindll::pinIkkuna()
{
    ppinkysely->pinIkkunaEngine();
}

void Pindll::receiveSignalFromEngine(QString pin)
{
    emit sendSignalToExe(pin);
}
