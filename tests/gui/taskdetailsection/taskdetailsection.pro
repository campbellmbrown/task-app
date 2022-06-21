QT += testlib widgets
TEMPLATE = app

SRCPATH = ../../../src

INCLUDEPATH = \
    $${SRCPATH} \

SOURCES += \
    taskdetailsectiontest.cpp \

HEADERS += \
    $${SRCPATH}/gui/taskdetailsection.h \
    $${SRCPATH}/models/priority.h \

SOURCES += \
    $${SRCPATH}/gui/taskdetailsection.cpp \
    $${SRCPATH}/models/priority.cpp \

FORMS += \
    $${SRCPATH}/gui/taskdetailsection.ui \
