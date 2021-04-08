#ifndef ENGINEREST_H
#define ENGINEREST_H

#include <QObject>
#include <QByteArray>
#include <QNetworkAccessManager>
#include <QtNetwork>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

class engineRest : public QObject
{
    Q_OBJECT
public:
    engineRest(QObject *parent = nullptr);
    ~engineRest();
    void tiedot(int idasiakas);
private:
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
public slots:


signals:
    void signalToInterface(QNetworkReply*);
    void sendToInterface(QNetworkReply*);
};

#endif // ENGINEREST_H
