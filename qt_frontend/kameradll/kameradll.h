#ifndef KAMERADLL_H
#define KAMERADLL_H

#include "kameradll_global.h"
#include "enginekamera.h"

class KAMERADLL_EXPORT Kameradll : public QObject
{
    Q_OBJECT
public:
    Kameradll(QObject *parent = nullptr);
    ~Kameradll();
    void otaKuva();
private:
    enginekamera *penginekamera;
public slots:
    void saved(QString);
signals:
    void sendPathToExe(QString);
};

#endif // KAMERADLL_H
