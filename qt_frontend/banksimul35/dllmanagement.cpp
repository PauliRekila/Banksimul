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
   // pDllrestapi->deleteManager();
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
    korttinumero = "600064972";
    ppindll->pinIkkuna();
}

void dllmanagement::receiveTiedotFromRestapi(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();

    qDebug() << "receiveFromPindll";

    if(taulu == "kortti"){
        arvo_1 = json_obj["idtili"].toString();
        arvo_2 = QString::number(json_obj["idasiakas"].toInt());
        qDebug() << arvo_2 << "id: ";
        tili = arvo_1;
        //getAsiakasNimi(arvo_2);
        taulu = "asiakas";
        getTiedot(taulu, arvo_2);
    }
    else if (taulu == "asiakas") {
        arvo_1 = json_obj["enimi"].toString()+" "+json_obj["snimi"].toString();
        pmenu->tervetuloaAsiakas(arvo_1);
        ppindll->sendLopeta();
        qDebug() << "Arvo1 asiakas nimi" << arvo_1;
    }
    else {
        qDebug() << "Funktiot ei tapahdu" << taulu;
    }

    reply->deleteLater();
    deleteManager();
}

void dllmanagement::receiveKorttiFromRestapi(QNetworkReply* reply)
{

    QString response_data=reply->readAll();

    if (response_data == "true")
    {
        qDebug() << response_data;
        taulu = "kortti";
        getTiedot(taulu, korttinumero);
        reply->deleteLater();
        deleteManager();
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
    pilmoitus->lukittuIlmoitus();
}

void dllmanagement::receiveDataFromSerialport(QString)
{
    //ppindll->pinIkkuna();
    //ppindll->yritykset=0;
}
