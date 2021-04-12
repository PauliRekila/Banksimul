#include "pindll.h"

Pindll::Pindll(QObject *parent) : QObject(parent)
{
}

void Pindll::kirjautuminen(short pin)
{
    emit sendSignalToExe(pin);
}
