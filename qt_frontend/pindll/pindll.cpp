#include "pindll.h"

Pindll::Pindll(QObject *parent) : QObject(parent)
{
    ppinkysely = new pinkysely;
}

Pindll::~Pindll()
{
    delete ppinkysely;
    ppinkysely = nullptr;
}

void Pindll::kirjautuminen(QString pin)
{
    emit sendSignalToExe(pin);
}

void Pindll::pinIkkuna()
{
    ppinkysely->pinIkkunaEngine();
}
