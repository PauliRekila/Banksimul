#include "engine.h"

engine::engine(QObject *parent) : QObject(parent)
{
    pQSerialPort = new QSerialPort;

    connect(pQSerialPort, SIGNAL(readyRead()),
            this, SLOT(readData()));

    pQSerialPort->setPortName("COM3");
    qDebug() << pQSerialPort->portName();

    pQSerialPort->setBaudRate(QSerialPort::Baud9600);
    pQSerialPort->setDataBits(QSerialPort::Data8);
    pQSerialPort->setParity(QSerialPort::NoParity);
    pQSerialPort->setStopBits(QSerialPort::OneStop);
    pQSerialPort->setFlowControl(QSerialPort::NoFlowControl);
    //pQSerialPort->setFlowControl(QSerialPort::HardwareControl);
    pQSerialPort->open(QIODevice::ReadWrite);

    qDebug() << "engine luotu";
}
engine::~engine()
{
    delete pQSerialPort;
    pQSerialPort = nullptr;

}

void engine::readData()
{

    QString data = "";
    data = pQSerialPort->readAll();
    data.remove(0,4);
    data.chop(3);
    if (data.length() >=10)
    {
        qDebug() << "lukuvirhe";
        emit errToInterface();
    }
    else
    {
    qDebug() << data;
    pQSerialPort->close();
    qDebug() << "Suljetaan lopuksi";
    emit signalToInterface(data);
    }
}
