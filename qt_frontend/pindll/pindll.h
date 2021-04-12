#ifndef PINDLL_H
#define PINDLL_H

#include <QDebug>
#include <QObject>
#include <QDialog>
#include <QLineEdit>
#include "pindll_global.h"


class PINDLL_EXPORT Pindll : public QObject
{
    Q_OBJECT
public:
    Pindll(QObject *parent = nullptr);
    void kirjautuminen(short);

signals:
    void sendSignalToExe(short);

public slots:

};

#endif // PINDLL_H
