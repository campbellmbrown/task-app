QT += testlib widgets
TEMPLATE = app

SRCPATH = ../../../src

INCLUDEPATH = \
    $${SRCPATH} \

SOURCES += \
    tasktablemodeltest.cpp \

HEADERS += \
    $${SRCPATH}/gui/tasktablemodel.h \
    $${SRCPATH}/models/priority.h \

SOURCES += \
    $${SRCPATH}/gui/tasktablemodel.cpp \
    $${SRCPATH}/models/priority.cpp \
