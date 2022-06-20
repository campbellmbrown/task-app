QT += testlib widgets
TEMPLATE = app

SRCPATH = ../../../src

INCLUDEPATH = \
    $${SRCPATH} \

SOURCES += \
    detailsectiontest.cpp \

HEADERS += \
    $${SRCPATH}/gui/detailsection.h \
    $${SRCPATH}/models/priority.h \

SOURCES += \
    $${SRCPATH}/gui/detailsection.cpp \
    $${SRCPATH}/models/priority.cpp \

FORMS += \
    $${SRCPATH}/gui/detailsection.ui \
