#include "enginekamera.h"

enginekamera::enginekamera(QObject *parent) : QObject(parent)
{
    pkamera = new QCamera;
    pcap = new QCameraImageCapture(pkamera);
    pkamera->setCaptureMode(QCamera::CaptureStillImage);
    pcap->setCaptureDestination(QCameraImageCapture::CaptureToFile);
    pkamera->start();
    QObject::connect(pcap, SIGNAL(imageSaved(int,QString)), this,SLOT(pathSaved(int,QString)));

}
enginekamera::~enginekamera()
{
    delete pkamera;
    pkamera = nullptr;
    delete pcap;
    pcap = nullptr;
}


void enginekamera::otaKuvaEngine()
{

    pkamera->searchAndLock();
    pcap->capture();
    pkamera->unlock();

}

void enginekamera::pathSaved(int,QString path)
{
    emit pathToInterface(path);
}
