QT += testlib widgets
TEMPLATE = app

SRCPATH = ../../../src

INCLUDEPATH = \
    $${SRCPATH} \

SOURCES += \
    detailsviewtest.cpp \

HEADERS += \
    $${SRCPATH}/gui/detailsview.h \

SOURCES += \
    $${SRCPATH}/gui/detailsview.cpp \

FORMS += \
    $${SRCPATH}/gui/detailsview.ui \
