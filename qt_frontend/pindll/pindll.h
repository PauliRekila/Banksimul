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

private:
    pinkysely *ppinkysely;

signals:
    void sendSignalToExe(QString);

public slots:
    void receiveSignalFromEngine(QString);
};

#endif // PINDLL_H
