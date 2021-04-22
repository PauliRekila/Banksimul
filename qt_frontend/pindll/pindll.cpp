#include "pindll.h"

Pindll::Pindll(QObject *parent) : QObject(parent)
{
    ppinkysely = new pinkysely;

    connect(ppinkysely, SIGNAL(signalToInterface(QString)),
            this, SLOT(receiveSignalFromEngine(QString)));
    connect(ppinkysely, SIGNAL(kirjaudutaanUlos()),
            this, SLOT(receiveKirjaudutaanUlosFromEngine()));
}

Pindll::~Pindll()
{
    delete ppinkysely;
    ppinkysely = nullptr;
}

void Pindll::pinIkkuna()
{
/* AUKAISEE ENGINESSÄ KIRJAUTUMIS DIALOGIN */
    yritykset = 0;
    ppinkysely->pinIkkunaEngine();
}

void Pindll::sendLopeta()
{
    ppinkysely->lopeta();
}

void Pindll::wrongPin()
{
/* LASKEE YRITYKSET, LÄHETTÄÄ VIRHEILMOITUKSEN JA JÄÄDYTTÄÄ KORTIN */
    yritykset++;

    if (yritykset < 3)
    {
        ppinkysely->virheIlmoitus(yritykset);
    }
    else
    {
        emit korttiLukittu();
        ppinkysely->lopeta();
        qDebug() << "Kortti lukittu";
    }
}

void Pindll::receiveSignalFromEngine(QString pin)
{
    emit sendSignalToExe(pin);
}

void Pindll::receiveKirjaudutaanUlosFromEngine()
{
    emit kirjauduUlosExeen();
}
