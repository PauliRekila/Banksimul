#include "engine.h"

engine::engine(QObject *parent) : QObject(parent)
{   
    pQSerialPort = new QSerialPort;   

    connect(pQSerialPort, SIGNAL(readyRead()),
            this, SLOT(readData()));

    avaaPortti();    
}
engine::~engine()
{
    delete pQSerialPort;
    pQSerialPort = nullptr;
}

void engine::avaaPortti()
{
/* ALUSTETAAN SARJAPORTIN AVAAMINEN */

    pQSerialPort->setPortName("COM3");    
    pQSerialPort->setBaudRate(QSerialPort::Baud9600);
    pQSerialPort->setDataBits(QSerialPort::Data8);
    pQSerialPort->setParity(QSerialPort::NoParity);
    pQSerialPort->setStopBits(QSerialPort::OneStop);
    pQSerialPort->setFlowControl(QSerialPort::NoFlowControl);    
    pQSerialPort->open(QIODevice::ReadWrite);
}

void engine::readData()
{
/* LUETAAN KORTTINUMERO JA POISTETAAN YLIMÄÄRÄINEN TIETO LUKIJALTA */

    QString data;
    data.clear();
    data = pQSerialPort->readAll();
    data.remove(0,4);
    data.chop(3);

/* VARMISTETAAN, ETTÄ KORTTI LUETAAN VAIN KERRAN */

    if (data.length() >=10)
    {        
        qDebug() << "lukuvirhe";
        emit errToInterface();
    }
    else
    {        
        pQSerialPort->close();
        emit signalToInterface(data);
    }
}
