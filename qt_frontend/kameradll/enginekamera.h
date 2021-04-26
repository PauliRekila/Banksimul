#ifndef ENGINEKAMERA_H
#define ENGINEKAMERA_H

#include <QObject>
#include <QCamera>
#include <QCameraImageCapture>
#include <QThread>


class enginekamera : public QObject
{
    Q_OBJECT
public:
    enginekamera(QObject *parent = nullptr);
    ~enginekamera();
    void otaKuvaEngine();

public slots:
    void pathSaved(int,QString);

private:
    QCamera *pkamera;
    QCameraImageCapture *pcap;

signals:
    void pathToInterface(QString);

};

#endif // ENGINEKAMERA_H
