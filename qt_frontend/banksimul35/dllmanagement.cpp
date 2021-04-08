#include "dllmanagement.h"
#include "dllrestapi.h"

dllmanagement::dllmanagement(QObject *parent) : QObject(parent)
{
  //  pEngineRest = new engineRest;
    pInterfaceRest = new Dllrestapi;
    pMenu = new menu;
    connect(pInterfaceRest, SIGNAL(sendToExe(QNetworkReply*)),
            this, SLOT(getAsiakasSlot(QNetworkReply*reply)));
}

dllmanagement::~dllmanagement()
{
    delete pEngineRest;
    pEngineRest = nullptr;
    delete pMenu;
    pMenu = nullptr;
}

void dllmanagement::getAsiakasSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString asiakas;
    foreach (const QJsonValue &value, json_array) {
    QJsonObject json_obj = value.toObject();
    asiakas="Tervetuloa, "+json_obj["enimi"].toString()+" "+json_obj["snimi"].toString()+"\r";
    }
    qDebug()<<asiakas;
    pMenu->menuName(asiakas);
    reply->deleteLater();
  //  pEngineRest->manager->deleteLater();
}
