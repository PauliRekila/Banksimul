#include "enginerest.h"

enginerest::enginerest(QObject *parent) : QObject(parent)
{

}

void enginerest::tiedot(QString taulu, QString id)
{
/*KÄYTETÄÄN ASIAKKAAN TIETOJEN HAKEMISEEN*/

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
/*KÄYTETÄÄN KORTIN LUKITSEMISEEN JOS PIN ON VÄÄRIN*/

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
/*KÄYTETÄÄN SISÄÄNKIRJAUTUMISEEN*/

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

void enginerest::nosto(int idtili, double maara)
{
/*LISÄÄ UUDEN NOSTOTAPAHTUMAN*/

    QString site_url="http://localhost:3000/kortti/uusi_tapahtuma";
    QString credentials="banksimul35:1234";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    QJsonObject obj;
    obj["id"] = idtili;
    obj["maara"] = -maara;
    QJsonDocument doc(obj);
    QByteArray uusiNosto = doc.toJson();
    manager = new QNetworkAccessManager(this);
    manager->post(request, uusiNosto);

}

void enginerest::receiveNetworkReplyKortti(QNetworkReply *)
{
    emit sendKorttiToInterface(reply);
}

void enginerest::receiveNetworkReplyTiedot(QNetworkReply *reply)
{
    emit sendTiedotToInterface(reply);
}
