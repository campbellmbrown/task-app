QT += testlib widgets
TEMPLATE = app

SRCPATH = ../../../src

INCLUDEPATH = \
    $${SRCPATH} \

SOURCES += \
    tasklistviewtest.cpp \

HEADERS += \
    $${SRCPATH}/gui/tasklistview.h \

SOURCES += \
    $${SRCPATH}/gui/tasklistview.cpp \

FORMS += \
    $${SRCPATH}/gui/tasklistview.ui \
