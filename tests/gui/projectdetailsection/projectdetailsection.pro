QT += testlib widgets
TEMPLATE = app

SRCPATH = ../../../src

INCLUDEPATH = \
    $${SRCPATH} \

SOURCES += \
    projectdetailsectiontest.cpp \

HEADERS += \
    $${SRCPATH}/gui/projectdetailsection.h \
    $${SRCPATH}/models/projectcollection.h \

SOURCES += \
    $${SRCPATH}/gui/projectdetailsection.cpp \
    $${SRCPATH}/models/projectcollection.cpp \

FORMS += \
    $${SRCPATH}/gui/projectdetailsection.ui \

DEFINES += IGNORE_DIALOG
