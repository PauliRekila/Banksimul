#include "kameradll.h"

Kameradll::Kameradll(QObject *parent) : QObject(parent)
{
    penginekamera = new enginekamera;
    connect(penginekamera, SIGNAL(pathToInterface(QString)), this,SLOT(saved(QString)));
}

Kameradll::~Kameradll()
{
    delete penginekamera;
    penginekamera = nullptr;
}

void Kameradll::otaKuva()
{
    penginekamera->otaKuvaEngine();
}

void Kameradll::saved(QString path)
{
    emit sendPathToExe(path);
}
