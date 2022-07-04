QT += testlib widgets
TEMPLATE = app

SRCPATH = ../../../src

INCLUDEPATH = \
    $${SRCPATH} \

SOURCES += \
    projecttablemodeltest.cpp \

HEADERS += \
    $${SRCPATH}/gui/projecttablemodel.h \
    $${SRCPATH}/models/projectcollection.h \

SOURCES += \
    $${SRCPATH}/gui/projecttablemodel.cpp \
    $${SRCPATH}/models/projectcollection.cpp \
