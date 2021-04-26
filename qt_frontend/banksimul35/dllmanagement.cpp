#include "dllmanagement.h"

dllmanagement::dllmanagement(QObject *parent) : QObject(parent)
{
    pDllrestapi = new Dllrestapi;
    pDllserialport = new Dllserialport;
    ppindll = new Pindll;
    pkameradll = new Kameradll;

    pmenu = new menu;
    pilmoitus = new ilmoitus;
    pnosto = new nosto;
    psaldo = new saldo;
    ptapahtumat = new tapahtumat;

    connect(pDllrestapi, SIGNAL(sendTiedotToExe(QNetworkReply*)),
            this, SLOT(receiveTiedotFromRestapi(QNetworkReply*)));
    connect(pDllrestapi, SIGNAL(sendKorttiToExe(QNetworkReply*)),
            this, SLOT(receiveKorttiFromRestapi(QNetworkReply*)));
    connect(pDllserialport, SIGNAL(sendDataToExe(QString)),
            this, SLOT(receiveDataFromSerialport(QString)));
    connect(ppindll, SIGNAL(sendSignalToExe(QString)),
            this, SLOT(receiveSignalFromPindll(QString)));
    connect(ppindll, SIGNAL(korttiLukittu()),
            this, SLOT(receiveLukittuFromPindll()));
    connect(pmenu, SIGNAL(kirjauduUlos()),
            this, SLOT(receiveKirjauduUlosFromMenu()));
    connect(pmenu, SIGNAL(requestSaldo()),
            this, SLOT(receiveRequestSaldoFromMenu()));
    connect(pmenu, SIGNAL(requestTapahtumat()),
            this, SLOT(receiveRequestTapahtumatFromMenu()));
    connect(pmenu, SIGNAL(requestNosto()),
            this, SLOT(receiveRequestNostoFromMenu()));
    connect(pnosto, SIGNAL(eiRahaa()),
            this, SLOT(receiveEiRahaaFromNosto()));
    connect(pnosto, SIGNAL(nostaMaara(double)),
            this, SLOT(receiveNostaMaaraFromNosto(double)));
    connect(pnosto, SIGNAL(menuTimer()),
            this, SLOT(receiveMenuTimer()));
    connect(ptapahtumat, SIGNAL(menuTimer()),
            this, SLOT(receiveMenuTimer()));
    connect(psaldo, SIGNAL(menuTimer()),
            this, SLOT(receiveMenuTimer()));
    connect(pilmoitus, SIGNAL(nostaTimer()),
            this, SLOT(receiveNostaTimerFromIlmoitus()));
    connect(ppindll, SIGNAL(kirjauduUlosExeen()),
            this, SLOT(receiveKirjauduUlosFromMenu()));
    connect(pkameradll, SIGNAL(sendPathToExe(QString)),
            this, SLOT(receivePathFromKameradll(QString)));
}

dllmanagement::~dllmanagement()
{
    delete pDllrestapi;
    pDllrestapi = nullptr;
    delete pDllserialport;
    pDllserialport = nullptr;
    delete ppindll;
    ppindll = nullptr;
    delete pkameradll;
    pkameradll = nullptr;
    delete pmenu;
    pmenu = nullptr;
    delete pilmoitus;
    pilmoitus = nullptr;
    delete pnosto;
    pnosto = nullptr;
    delete psaldo;
    psaldo = nullptr;
    delete ptapahtumat;
    ptapahtumat = nullptr;
}

void dllmanagement::deleteManager()
{
    pDllrestapi->deleteManager();
}

void dllmanagement::getTiedot(QString taulu, QString id)
{
    pDllrestapi->sendTiedot(taulu, id);
}

void dllmanagement::getKortti(QString korttinumero, QString pin)
{
    pDllrestapi->sendKortti(korttinumero, pin);
}

void dllmanagement::getAsiakasNimi(QString id)
{
    taulu = "asiakas";
    getTiedot(taulu, id);
}

void dllmanagement::saldoTaiTapahtumatTaiNosto()
{
/* RIIPPUEN SIITÄ MITÄ NAPPIA PAINETTIIN MENUSSA KÄYNNISTETÄÄN ERI IKKUNA */

    if (painettunappi == "saldo")
    {
        psaldo->saldoIkkuna(asiakas,tilinsaldo,tilintapahtumat);
    }

    else if (painettunappi == "tapahtumat")
    {
        ptapahtumat->tapahtumatIkkuna(asiakas,tilinsaldo,tilintapahtumat);
    }

    else if (painettunappi == "nosto")
    {
        pnosto->nostoIkkuna(asiakas, tilinsaldo);
    }
}

void dllmanagement::receiveTiedotFromRestapi(QNetworkReply *reply)
{
/* LUKEE SAADUN VASTAUKSEN JA RIIPPUEN SIITÄ MISTÄ TAULUSTA TIEDOT LUETTIIN KÄYTTÄÄ TIETOJA ERI TAVALLA */

    QByteArray response_data=reply->readAll();

    if(taulu == "kortti")
    {
        QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
        QJsonObject json_obj = json_doc.object();

        tili = QString::number(json_obj["idtili"].toInt());
        arvo_2 = QString::number(json_obj["idasiakas"].toInt());
        arvo_3 = QString::number(json_obj["lukittu"].toInt());

/* TARKISTAA ONKO KORTTI LUKITTU. JOS EI OLE LUKITTU AUKEAA PIN-IKKUNA.*/

        if(arvo_3 == "0")
        {
            ppindll->pinIkkuna();            
        }
        else
        {
            pilmoitus->lukossaIlmoitus();
        }

        pkameradll->otaKuva();
    }

    else if (taulu == "asiakas")
    {
        QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
        QJsonObject json_obj = json_doc.object();

        asiakas = json_obj["enimi"].toString()+" "+json_obj["snimi"].toString();
        ppindll->sendLopeta();
        pmenu->tervetuloaAsiakas(asiakas);
    }

    else if (taulu == "tili")
    {
        QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
        QJsonObject json_obj = json_doc.object();

        tilinsaldo = QString::number(json_obj["saldo"].toDouble());
        qDebug() << "Saldo: " << tilinsaldo;
        qDebug() << "Tili: " << tili;
        saldoTaiTapahtumatTaiNosto();
    }

    else if (taulu == "tapahtumat")
    {
        QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
        QJsonObject json_obj = json_doc.object();
        QJsonArray json_array = json_doc.array();
        tilintapahtumat.clear();

        foreach (const QJsonValue &value, json_array)
        {
            QJsonObject json_obj = value.toObject();
            tilintapahtumat+= json_obj["paivays"].toString()+"\t"+QString::number(json_obj["maara"].toDouble())+"\t"+json_obj["tyyppi"].toString()+"\t\t"+json_obj["tilinumero"].toString()+"\r";
            tilintapahtumat.replaceInStrings("T", " ");
            tilintapahtumat.replaceInStrings(".000Z", "");
        }

/* LAJITTELEE TAPAHTUMAT SITEN, ETTÄ UUSIMMAT TAPAHTUMAT OVAT ENSIMMÄISENÄ LISTASSA */

        sort(tilintapahtumat.begin(), tilintapahtumat.end(), std::greater<QString>());

        taulu = "tili";

        getTiedot(taulu, tili);
    }

    else
    {
        qDebug() << "Funktiot ei tapahdu" << taulu;
    }

    reply->deleteLater();
}

void dllmanagement::receiveKorttiFromRestapi(QNetworkReply* reply)
{

/* JOS KIRJAUTUMINEN ONNISTUI SIIRTYY HAKEMAAN TIETOJA, MUUTEN ANTAA VIRHEVIESTIN */

    QString response_data=reply->readAll();

    if (response_data == "true")
    {
        taulu = "asiakas";
        getTiedot(taulu, arvo_2);
        reply->deleteLater();
    }

    else if (response_data == "false")
    {
        ppindll->wrongPin();
    }

    else
    {
        qDebug() << "Kirjautumisvirhe";
    }
}

void dllmanagement::receiveSignalFromPindll(QString pin)
{
    getKortti(korttinumero, pin);
}

void dllmanagement::receiveLukittuFromPindll()
{
    pDllrestapi->sendLukitus(korttinumero);
    pilmoitus->lukittuIlmoitus();
}

void dllmanagement::receiveDataFromSerialport(QString korttinumeroSerial)
{
    taulu = "kortti";
    korttinumero = korttinumeroSerial;

    getTiedot(taulu, korttinumero);

}

void dllmanagement::receiveKirjauduUlosFromMenu()
{
/* TYHJENTÄÄ KAIKKI MUUTTUJAT */

    korttinumero.clear();
    taulu.clear();
    asiakas.clear();
    tilinsaldo.clear();
    tili.clear();
    arvo_2.clear();
    arvo_3.clear();
    tilintapahtumat.clear();

    deleteManager();

    pDllserialport->portinAvaus();
}

void dllmanagement::receiveRequestSaldoFromMenu()
{
    painettunappi = "saldo";
    taulu = "tapahtumat";

    getTiedot(taulu, tili);
}

void dllmanagement::receiveRequestTapahtumatFromMenu()
{
    painettunappi = "tapahtumat";
    taulu = "tapahtumat";

    getTiedot(taulu, tili);
}

void dllmanagement::receiveRequestNostoFromMenu()
{
    painettunappi = "nosto";
    taulu = "tapahtumat";

    getTiedot(taulu, tili);
}

void dllmanagement::receiveNostaMaaraFromNosto(double maara)
{
    pDllrestapi->sendNosto(tili.toInt(), maara);
}

void dllmanagement::receiveEiRahaaFromNosto()
{
    pilmoitus->eiRahaaIlmoitus();
}

void dllmanagement::receiveMenuTimer()
{
    pmenu->timer->start(30000);
}

void dllmanagement::receiveNostaTimerFromIlmoitus()
{
    pnosto->timer->start(20000);
}

void dllmanagement::receivePathFromKameradll(QString path)
{
    pDllrestapi->sendKameraPath(path);
}
