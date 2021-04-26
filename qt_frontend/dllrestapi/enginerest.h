#ifndef ENGINEREST_H
#define ENGINEREST_H

#include <QObject>
#include <QDebug>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QByteArray>
#include <QJsonArray>
#include <QJsonObject>


class enginerest : public QObject
{
    Q_OBJECT

public:
    enginerest(QObject *parent = nullptr);
    void tiedot(QString, QString);
    void lukitus(QString);
    void kirjautuminen(QString, QString);
    void nosto(int, double);
    void sendKameraEngine(QString);
    QNetworkAccessManager * manager;    

private:
    QNetworkReply * reply;

signals:
    void sendTiedotToInterface(QNetworkReply*);
    void sendKorttiToInterface(QNetworkReply*);

public slots:
    void receiveNetworkReplyTiedot(QNetworkReply*);
    void receiveNetworkReplyKortti(QNetworkReply*);

};

#endif // ENGINEREST_H
