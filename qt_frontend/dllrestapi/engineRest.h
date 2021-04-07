#ifndef ENGINEREST_H
#define ENGINEREST_H

#include <QObject>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QByteArray>
#include <QNetworkReply>
#include <QJsonArray>
#include <QJsonObject>

class engineRest : public QObject
{
    Q_OBJECT
public:
    engineRest(QObject *parent = nullptr);
    void tiedot();
private:
    QNetworkReply *reply;
    QNetworkAccessManager *manager;

private slots:
    void authenticationRequired(QNetworkReply *reply, QAuthenticator *authenticator);
    void encrypted(QNetworkReply *reply);
    void finished(QNetworkReply *reply);
public slots:
//    void getAsiakasSlot(QNetworkReply *reply);
signals:
    void sendSignalToInterface(QString);

};

#endif // ENGINEREST_H
