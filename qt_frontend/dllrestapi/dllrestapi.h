#ifndef DLLRESTAPI_H
#define DLLRESTAPI_H

#include "dllrestapi_global.h"
#include "engineRest.h"

class DLLRESTAPI_EXPORT Dllrestapi : public QObject
{
    Q_OBJECT
public:
    Dllrestapi(QObject *parent = nullptr);
    ~Dllrestapi();
private:
    engineRest *pEngineRest;


private slots:

public slots:
   void receiveSignalFromEngine(QString);
   void getAsiakasSlot(QNetworkReply*);
signals:
   void sendInfoToExe(QString);

};

#endif // DLLRESTAPI_H
