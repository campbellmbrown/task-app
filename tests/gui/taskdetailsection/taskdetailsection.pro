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
    $${SRCPATH}/models/projectcollection.h \

SOURCES += \
    $${SRCPATH}/gui/taskdetailsection.cpp \
    $${SRCPATH}/models/priority.cpp \
    $${SRCPATH}/models/projectcollection.cpp \

FORMS += \
    $${SRCPATH}/gui/taskdetailsection.ui \
