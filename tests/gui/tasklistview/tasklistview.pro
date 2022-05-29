QT += testlib widgets
TEMPLATE = app

SRCPATH = ../../../src

INCLUDEPATH = \
    $${SRCPATH} \

SOURCES += \
    tasklistviewtest.cpp \

HEADERS += \
    $${SRCPATH}/dialogs/createtaskdlg.h \
    $${SRCPATH}/gui/tasklistview.h \

SOURCES += \
    $${SRCPATH}/dialogs/createtaskdlg.cpp \
    $${SRCPATH}/gui/tasklistview.cpp \

FORMS += \
    $${SRCPATH}/dialogs/createtaskdlg.ui \
    $${SRCPATH}/gui/tasklistview.ui \
