#ifndef DLLRESTAPI_H
#define DLLRESTAPI_H

#include "dllrestapi_global.h"
#include "enginerest.h"

class DLLRESTAPI_EXPORT Dllrestapi : public QObject
{
    Q_OBJECT
public:
    Dllrestapi(QObject *parent = nullptr);
    ~Dllrestapi();
    void sendTiedot(QString, QString);
    void sendKortti(QString, QString);
    void sendLukitus(QString);
    void deleteManager();
    void sendNosto(int, double);

private:
    enginerest * penginerest;
public slots:
    void receiveTiedotFromEngine(QNetworkReply*);
    void receiveKorttiFromEngine(QNetworkReply*);

signals:
    void sendTiedotToExe(QNetworkReply*);
    void sendKorttiToExe(QNetworkReply*);
};

#endif // DLLRESTAPI_H
