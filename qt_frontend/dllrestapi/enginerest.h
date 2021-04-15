#ifndef ENGINEREST_H
#define ENGINEREST_H

#include <QObject>
#include <QDebug>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QByteArray>
#include <QNetworkReply>
#include <QJsonArray>
#include <QJsonObject>


class enginerest : public QObject
{
    Q_OBJECT
public:
    enginerest(QObject *parent = nullptr);
    void tiedot(QString);
    QNetworkAccessManager * manager;
private:
    QNetworkReply * reply;

signals:
    void sendSignalToInterface(QNetworkReply*);

public slots:
    void receiveNetworkReply(QNetworkReply*);


};

#endif // ENGINEREST_H
