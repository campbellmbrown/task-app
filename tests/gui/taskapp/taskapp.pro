QT += testlib widgets
TEMPLATE = app

SRCPATH = ../../src

INCLUDEPATH = \
    $${SRCPATH} \

SOURCES += \
    taskapptest.cpp \

HEADERS += \
    $${SRCPATH}/gui/taskapp.h \

SOURCES += \
    $${SRCPATH}/gui/taskapp.cpp \

FORMS += \
    $${SRCPATH}/gui/taskapp.ui \
