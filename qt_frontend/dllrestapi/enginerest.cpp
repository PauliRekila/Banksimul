#include "enginerest.h"

enginerest::enginerest(QObject *parent) : QObject(parent)
{

}

void enginerest::tiedot(QString taulu, QString id)
{
    qDebug() << "Toimiiko yhteys" << taulu << id;
    QString site_url="http://localhost:3000/"+taulu+"/"+id;
    QString credentials="banksimul35:1234";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
    this, SLOT(receiveNetworkReplyTiedot(QNetworkReply*)));
    reply = manager->get(request);
}

void enginerest::lukitus(QString korttinumero)
{
    QString site_url="http://localhost:3000/kortti/"+korttinumero;
    QString credentials="banksimul35:1234";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    QJsonObject obj;
    obj["lukittu"] = 1;
    QJsonDocument doc(obj);
    QByteArray lukittu = doc.toJson();
    manager = new QNetworkAccessManager(this);
    manager->put(request, lukittu);
}

void enginerest::kirjautuminen(QString korttinumero, QString pin)
{
    QString site_url="http://localhost:3000/login";
    QString credentials="banksimul35:1234";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    QJsonObject obj;
    obj["korttinumero"] = korttinumero;
    obj["pinkoodi"] = pin;
    QJsonDocument doc(obj);
    QByteArray login = doc.toJson();
    manager = new QNetworkAccessManager(this);
    reply = manager->post(request, login);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
    this, SLOT(receiveNetworkReplyKortti(QNetworkReply*)));
}

void enginerest::receiveNetworkReplyKortti(QNetworkReply *)
{
    emit sendKorttiToInterface(reply);
}

void enginerest::receiveNetworkReplyTiedot(QNetworkReply *reply)
{
    emit sendTiedotToInterface(reply);
    qDebug() << "QReply: " << reply;
}
