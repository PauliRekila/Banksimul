QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dllmanagement.cpp \
    ilmoitus.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    nosto.cpp \
    saldo.cpp \
    tapahtumat.cpp

HEADERS += \
    dllmanagement.h \
    ilmoitus.h \
    mainwindow.h \
    menu.h \
    nosto.h \
    saldo.h \
    tapahtumat.h

FORMS += \
    ilmoitus.ui \
    mainwindow.ui \
    menu.ui \
    nosto.ui \
    saldo.ui \
    tapahtumat.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32: LIBS += -L$$PWD/../build-dllrestapi-Desktop_Qt_5_15_2_MinGW_32_bit-Debug/debug/ -ldllrestapi

INCLUDEPATH += $$PWD/../dllrestapi
DEPENDPATH += $$PWD/../dllrestapi

win32: LIBS += -L$$PWD/../build-pindll-Desktop_Qt_5_15_2_MinGW_32_bit-Debug/debug/ -lpindll

INCLUDEPATH += $$PWD/../pindll
DEPENDPATH += $$PWD/../pindll
