QT += testlib
TEMPLATE = app

SRCPATH = ../../../src

INCLUDEPATH = \
    $${SRCPATH} \

SOURCES += \
    projectscollectiontest.cpp \

HEADERS += \
    $${SRCPATH}/models/projectscollection.h \

SOURCES += \
    $${SRCPATH}/models/projectscollection.cpp \
