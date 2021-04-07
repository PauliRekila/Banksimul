#include "enginerest.h"

engineRest::engineRest(QObject *parent) : QObject(parent)
{

}

engineRest::~engineRest()
{

}

void engineRest::tiedot(int idasiakas)
{
    QString site_url="http://localhost:3000/asiakas/"+QString(idasiakas);
    QString credentials="banksimul35:1234";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader("Authorization", headerData.toLocal8Bit());
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
    this, SLOT(signalToInterface(QNetworkReply*)));
    reply = manager->get(request);
}


