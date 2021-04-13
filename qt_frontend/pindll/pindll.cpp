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

void Pindll::kirjautuminen(short pin)
{
    emit sendSignalToExe(pin);
}

void Pindll::testDialog()
{
    ppinkysely->testiDialogi2();
}
