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

class engineRest : public QObject
{
    Q_OBJECT
public:
    engineRest(QObject *parent = nullptr);
    ~engineRest();
    void tiedot(int idasiakas);
    QNetworkAccessManager *manager;
    QNetworkReply *reply;

private slots:

signals:
    void signalToInterface(QString);
};

#endif // ENGINEREST_H
