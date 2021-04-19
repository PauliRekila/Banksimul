#ifndef PINDLL_H
#define PINDLL_H

#include "pindll_global.h"
#include "pinkysely.h"


class PINDLL_EXPORT Pindll : public QObject
{
    Q_OBJECT
public:
    Pindll(QObject *parent = nullptr);
    ~Pindll();
    void pinIkkuna();
    void sendLopeta();
    void wrongPin();

private:
    pinkysely *ppinkysely;
    short yritykset = 0;

signals:
    void sendSignalToExe(QString);
    void korttiLukittu();

public slots:
    void receiveSignalFromEngine(QString);
};

#endif // PINDLL_H
