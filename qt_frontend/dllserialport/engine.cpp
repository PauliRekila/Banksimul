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

    if (pQSerialPort->open(QIODevice::ReadWrite))
    {
        qDebug() << "Portti aukesi" << Qt::endl;
    }

    else
    {
        qDebug() << "Ei aukea" << Qt::endl;
    }

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
    qDebug() << data;
    pQSerialPort->close();
    qDebug() << "Suljetaan lopuksi";
    emit signalToInterface(data);
}
