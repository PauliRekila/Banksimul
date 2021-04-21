#ifndef DLLSERIALPORT_H
#define DLLSERIALPORT_H

#include "dllserialport_global.h"
#include "engine.h"

class DLLSERIALPORT_EXPORT Dllserialport:public QObject
{
    Q_OBJECT
public:
    Dllserialport(QObject * parent = nullptr);
    ~Dllserialport();
    void portinAvaus();

private:
    engine * pEngine;
signals:
    void sendDataToExe(QString);
    void sendErrToExe();

public slots:
    void receiveSignalFromEngine(QString);
    void receiveErrFromEngine();
};

#endif // DLLSERIALPORT_H
