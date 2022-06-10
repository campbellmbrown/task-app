QT += testlib widgets
TEMPLATE = app

SRCPATH = ../../../src

INCLUDEPATH = \
    $${SRCPATH} \

SOURCES += \
    tasktableviewtest.cpp \

HEADERS += \
    $${SRCPATH}/gui/tasktableview.h \

SOURCES += \
    $${SRCPATH}/gui/tasktableview.cpp \
