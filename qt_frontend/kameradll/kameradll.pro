QT -= gui
QT += multimedia
QT += widgets

TEMPLATE = lib
DEFINES += KAMERADLL_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    enginekamera.cpp \
    kameradll.cpp

HEADERS += \
    enginekamera.h \
    kameradll_global.h \
    kameradll.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
