#include "dllmanagement.h"

dllmanagement::dllmanagement(QObject *parent) : QObject(parent)
{
    pDllrestapi = new Dllrestapi;
    pmenu = new menu;
    connect(pDllrestapi, SIGNAL(sendSignalToExe(QNetworkReply*)),
            this, SLOT(receiveSignalFromRestapi(QNetworkReply*)));
}

dllmanagement::~dllmanagement()
{
    delete pDllrestapi;
    pDllrestapi = nullptr;
    delete pmenu;
    pmenu = nullptr;
}

void dllmanagement::getAsiakasNimi()
{
    pDllrestapi->sendTiedot("1");
}

void dllmanagement::receiveSignalFromRestapi(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    QString asiakas;
    asiakas = json_obj["enimi"].toString()+" "+json_obj["snimi"].toString();
    qDebug() << asiakas;
    pmenu->tervetuloaAsiakas(asiakas);
    reply->deleteLater();
    //manager->deleteLater();
}
