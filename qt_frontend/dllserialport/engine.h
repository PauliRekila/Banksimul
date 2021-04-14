#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>
#include <QDebug>
#include <QList>
#include <QByteArray>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QIODevice>


class engine : public QObject
{
    Q_OBJECT
public:
    explicit engine(QObject *parent = nullptr);
    ~engine();

public slots:
    void readData();
private:
    QSerialPort * pQSerialPort;    

signals:
    void signalToInterface(QString);

};

#endif // ENGINE_H
