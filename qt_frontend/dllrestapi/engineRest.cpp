#include "engineRest.h"

engineRest::engineRest(QObject *parent) : QObject(parent)
{
    //reply = new QNetworkReply;

    connect(manager, &QNetworkAccessManager::authenticationRequired, this, &engineRest::authenticationRequired);
    connect(manager, &QNetworkAccessManager::encrypted, this, &engineRest::encrypted);


}

void engineRest::tiedot()
{

    QString site_url="http://localhost:3000/asiakas/1";
    QString credentials="banksimul35:1234";

    QNetworkRequest request((site_url));

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QByteArray data = credentials.toLocal8Bit().toBase64();

    QString headerData = "Basic " + data;

    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );

    manager = new QNetworkAccessManager(this);

    connect(manager, SIGNAL(finished(QNetworkReply*)),
    this, SLOT(getAsiakasSlot(QNetworkReply*)));


    reply = manager->get(request);

}

void engineRest::authenticationRequired(QNetworkReply *reply, QAuthenticator *authenticator)
{
    Q_UNUSED(reply);
    Q_UNUSED(authenticator);
}

void engineRest::encrypted(QNetworkReply *reply)
{
    Q_UNUSED(reply);
}

void engineRest::finished(QNetworkReply *reply)
{
    Q_UNUSED(reply);
}


