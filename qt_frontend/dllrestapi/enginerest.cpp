#include "enginerest.h"

enginerest::enginerest(QObject *parent) : QObject(parent)
{

}

void enginerest::tiedot(QString info)
{
    QString site_url="http://localhost:3000/asiakas/"+info;
    QString credentials="banksimul35:1234";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(receiveNetworkReply(QNetworkReply*)));
    reply = manager->get(request);
}

void enginerest::receiveNetworkReply(QNetworkReply *reply)
{
    emit sendSignalToInterface(reply);
}
