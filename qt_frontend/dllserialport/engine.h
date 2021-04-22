#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>
#include <QDebug>
#include <QList>
#include <QByteArray>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QIODevice>
#include <QTimer>


class engine : public QObject
{
    Q_OBJECT
public:
    engine(QObject *parent = nullptr);
    ~engine();
    void avaaPortti();

public slots:
    void readData();

private:
    QSerialPort * pQSerialPort;    

signals:
    void signalToInterface(QString);
    void errToInterface();

};

#endif // ENGINE_H
