#include "engine.h"

engine::engine(QObject *parent) : QObject(parent)
{
    pQSerialPort = new QSerialPort;
    pQSerialPortInfo = new QSerialPortInfo;
}

engine::~engine()
{
    delete pQSerialPort;
    pQSerialPort = nullptr;

    delete pQSerialPortInfo;
    pQSerialPortInfo = nullptr;
}

void engine::open()
{
    pQSerialPort->setPortName("COM52");
    qDebug() << pQSerialPort->portName();
    pQSerialPort->setBaudRate(9600);
    pQSerialPort->setDataBits(QSerialPort::Data8);
    pQSerialPort->setParity(QSerialPort::NoParity);
    pQSerialPort->setStopBits(QSerialPort::OneStop);
  //pQSerialPort->setFlowControl(QSerialPort::NoFlowControl);
    pQSerialPort->setFlowControl(QSerialPort::HardwareControl);

    if (!pQSerialPort->open(QIODevice::ReadWrite))
    {
        qDebug() << "Ei aukea" << Qt::endl;
    }

    else
    {
        qDebug() << "Portti aukesi" << Qt::endl;
        qDebug() << pQSerialPort->readAll();
    }

    qDebug() << "Suljetaan lopuksi";
    pQSerialPort->close();
}

void engine::info()
{
    QList<QSerialPortInfo> ports = pQSerialPortInfo->availablePorts();

    foreach(QSerialPortInfo info, ports)
    {
        emit signalToInterface(info.portName());
        emit signalToInterface(info.manufacturer());
    }
}
