QT += testlib widgets
TEMPLATE = app

SRCPATH = ../../../src

INCLUDEPATH = \
    $${SRCPATH} \

SOURCES += \
    detailsectiontest.cpp \

HEADERS += \
    $${SRCPATH}/gui/detailsection.h \

SOURCES += \
    $${SRCPATH}/gui/detailsection.cpp \

FORMS += \
    $${SRCPATH}/gui/detailsection.ui \
