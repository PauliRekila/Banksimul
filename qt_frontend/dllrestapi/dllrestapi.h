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
    void sendTiedot(QString);
    void deleteManager();

private:
    enginerest * penginerest;
public slots:
    void receiveSignalFromEngine(QNetworkReply*);

signals:
    void sendSignalToExe(QNetworkReply*);
};

#endif // DLLRESTAPI_H
