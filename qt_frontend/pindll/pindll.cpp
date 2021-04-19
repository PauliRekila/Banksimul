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

void Pindll::sendLopeta()
{
    ppinkysely->lopeta();
}

void Pindll::wrongPin()
{
    yritykset++;

    if (yritykset < 3) {
        ppinkysely->virheIlmoitus(yritykset);
    }
    else {
        emit korttiLukittu();
        ppinkysely->lopeta();
        qDebug() << "Kortti lukittu";
    }
}

void Pindll::receiveSignalFromEngine(QString pin)
{
    emit sendSignalToExe(pin);
}
