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

    void openReadClose();
    void readPortInfo();
private:
    engine * pEngine;
signals:
    void sendInfoToExe(QString);
public slots:
    void receiveSignalFromEngine(QString);
};

#endif // DLLSERIALPORT_H
