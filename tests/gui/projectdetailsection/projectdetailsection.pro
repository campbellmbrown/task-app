QT += testlib widgets
TEMPLATE = app

SRCPATH = ../../../src

INCLUDEPATH = \
    $${SRCPATH} \

SOURCES += \
    projectdetailsectiontest.cpp \

HEADERS += \
    $${SRCPATH}/gui/projectdetailsection.h \

SOURCES += \
    $${SRCPATH}/gui/projectdetailsection.cpp \

FORMS += \
    $${SRCPATH}/gui/projectdetailsection.ui \
