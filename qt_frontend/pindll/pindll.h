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
    void kirjautuminen(short);
    void testDialog();

private:
    pinkysely *ppinkysely;

signals:
    void sendSignalToExe(short);

public slots:

};

#endif // PINDLL_H
