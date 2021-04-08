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
private:
    engineRest * pEngineRest;
signals:
    void sendToExe(QNetworkReply*);
public slots:
    void receiveSignalFromEngine(QNetworkReply*);


};

#endif // DLLRESTAPI_H
