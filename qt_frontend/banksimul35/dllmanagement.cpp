#include "dllmanagement.h"

dllmanagement::dllmanagement(QObject *parent) : QObject(parent)
{
    pDllrestapi = new Dllrestapi;
    pDllserialport = new Dllserialport;
    ppindll = new Pindll;
    pmenu = new menu;
    connect(pDllrestapi, SIGNAL(sendTiedotToExe(QNetworkReply*)),
            this, SLOT(receiveTiedotFromRestapi(QNetworkReply*)));

    connect(pDllrestapi, SIGNAL(sendKorttiToExe(QNetworkReply*)),
            this, SLOT(receiveKorttiFromRestapi(QNetworkReply*)));

    connect(pDllserialport, SIGNAL(sendDataToExe(QString)),
            this, SLOT(receiveDataFromSerialport(QString)));

    connect(ppindll, SIGNAL(sendSignalToExe(QString)),
            this, SLOT(receiveSignalFromPindll(QString)));

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
}

void dllmanagement::deleteManager()
{
    pDllrestapi->deleteManager();
}

void dllmanagement::getTiedot(QString taulu, QString id)
{
    pDllrestapi->sendTiedot(taulu, id);
}

/*void dllmanagement::getKortti(QString korttinumero, QString pin)
{
    //pDllrestapi->sendKortti(korttinumero, pin);
}*/

void dllmanagement::receiveTiedotFromRestapi(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    QString asiakas;
    asiakas = json_obj["enimi"].toString()+" "+json_obj["snimi"].toString();
    qDebug() << asiakas;
    pmenu->tervetuloaAsiakas(asiakas);
    reply->deleteLater();
    deleteManager();
}

void dllmanagement::receiveKorttiFromRestapi(QNetworkReply* reply)
{
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    QString kortti;
    kortti = json_obj["enimi"].toString()+" "+json_obj["snimi"].toString();
    qDebug() << kortti;
    pmenu->tervetuloaAsiakas(kortti);
    reply->deleteLater();
    deleteManager();
}

void dllmanagement::receiveSignalFromPindll(QString pin)
{
    getTiedot("getId", korttinumero);
    qDebug() << "Signaali saatu pindll:stä exeen!" << pin;
}

void dllmanagement::receiveDataFromSerialport(QString)
{
    //getTiedot(getId, korttinumero)
    //getKortti(korttinumero);
}
