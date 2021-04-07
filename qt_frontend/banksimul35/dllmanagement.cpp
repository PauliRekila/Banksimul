#include "dllmanagement.h"

dllmanagement::dllmanagement(QObject *parent) : QObject(parent)
{
    pmenu = new menu;
    pEngineRest= new engineRest;
    connect(pEngineRest, SIGNAL(sendInfoToExe()),
            this, SLOT(receiveSignalFromDll()));

}

void dllmanagement::getAsiakasSlot()
{
  /*  QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    QString asiakas;
    asiakas=QString::number(json_obj["idasiakas"].toInt())+","+json_obj["enimi"].toString()+","+json_obj["snimi"].toString();
    qDebug()<<asiakas;
    ui->label_menu->setText(asiakas);
    pengine->reply->deleteLater();
    manager->deleteLater();   */
}

void dllmanagement::receiveSignalFromDll()
{

}
