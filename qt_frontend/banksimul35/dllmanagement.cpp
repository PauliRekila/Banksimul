#include "dllmanagement.h"

dllmanagement::dllmanagement(QObject *parent) : QObject(parent)
{
    pDllrestapi = new Dllrestapi;
    pDllserialport = new Dllserialport;
    ppindll = new Pindll;

    pmenu = new menu;
    pilmoitus = new ilmoitus;
    pnosto = new nosto;
    psaldo = new saldo;
    ptapahtumat = new tapahtumat;

    connect(pDllrestapi, SIGNAL(sendTiedotToExe(QNetworkReply*)),
            this, SLOT(receiveTiedotFromRestapi(QNetworkReply*)));

    connect(pDllrestapi, SIGNAL(sendKorttiToExe(QNetworkReply*)),
            this, SLOT(receiveKorttiFromRestapi(QNetworkReply*)));

    connect(pDllserialport, SIGNAL(sendDataToExe(QString)),
            this, SLOT(receiveDataFromSerialport(QString)));

    connect(ppindll, SIGNAL(sendSignalToExe(QString)),
            this, SLOT(receiveSignalFromPindll(QString)));

    connect(ppindll, SIGNAL(korttiLukittu()),
            this, SLOT(receiveLukittuFromPindll()));

    connect(pmenu, SIGNAL(kirjauduUlos()),
            this, SLOT(receiveKirjauduUlosFromMenu()));

}

dllmanagement::~dllmanagement()
{
    delete pDllrestapi;
    pDllrestapi = nullptr;
    delete pDllserialport;
    pDllserialport = nullptr;
    delete ppindll;
    ppindll = nullptr;

    delete pmenu;
    pmenu = nullptr;
    delete pilmoitus;
    pilmoitus = nullptr;
    delete pnosto;
    pnosto = nullptr;
    delete psaldo;
    psaldo = nullptr;
    delete ptapahtumat;
    ptapahtumat = nullptr;
}

void dllmanagement::deleteManager()
{
   pDllrestapi->deleteManager();
}

void dllmanagement::getTiedot(QString taulu, QString id)
{
    pDllrestapi->sendTiedot(taulu, id);
}

void dllmanagement::getKortti(QString korttinumero, QString pin)
{
    pDllrestapi->sendKortti(korttinumero, pin);
}

void dllmanagement::getAsiakasNimi(QString id)
{
    taulu = "asiakas";
    getTiedot(taulu, id);
}

void dllmanagement::pinAloitus()
{
    taulu = "kortti";
    korttinumero = "60006235E";
    getTiedot(taulu, korttinumero);
}

void dllmanagement::receiveTiedotFromRestapi(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();

    qDebug() << "receiveFromrestapi";

    if(taulu == "kortti"){
        arvo_1 = json_obj["idtili"].toString();
        arvo_2 = QString::number(json_obj["idasiakas"].toInt());
        arvo_3 = QString::number(json_obj["lukittu"].toInt());

        if(arvo_3 == "0"){
            tili = arvo_1;
            ppindll->pinIkkuna();
        }
        else {
            pilmoitus->lukossaIlmoitus();
        }
    }
    else if (taulu == "asiakas") {
        arvo_1 = json_obj["enimi"].toString()+" "+json_obj["snimi"].toString();
        ppindll->sendLopeta();
        pmenu->tervetuloaAsiakas(arvo_1);
    }
    else {
        qDebug() << "Funktiot ei tapahdu" << taulu;
    }

    reply->deleteLater();
}

void dllmanagement::receiveKorttiFromRestapi(QNetworkReply* reply)
{

    QString response_data=reply->readAll();

    if (response_data == "true")
    {
        qDebug() << response_data;
        taulu = "asiakas";
        getTiedot(taulu, arvo_2);
        reply->deleteLater();
    }
    else if (response_data == "false")
    {
        ppindll->wrongPin();
        qDebug() << response_data;
    }
    else
    {
        qDebug() << "Kirjautumisvirhe";
    }
}

void dllmanagement::receiveSignalFromPindll(QString pin)
{
    getKortti(korttinumero, pin);
}

void dllmanagement::receiveLukittuFromPindll()
{
    pDllrestapi->sendLukitus(korttinumero);
    pilmoitus->lukittuIlmoitus();
}

void dllmanagement::receiveDataFromSerialport(QString korttinumeroSerial)
{
    //taulu = "kortti";
    //korttinumero = korttinumeroSerial;
    //getTiedot(taulu, korttinumero);
    //ppindll->pinIkkuna();
    //ppindll->yritykset=0;
}

void dllmanagement::receiveKirjauduUlosFromMenu()
{
    korttinumero.clear();
    taulu.clear();
    tili.clear();
    arvo_1.clear();
    arvo_2.clear();
    arvo_3.clear();

    qDebug() << "Taulu" << taulu;

    deleteManager();
}
