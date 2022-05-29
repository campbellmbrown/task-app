QT += testlib widgets
TEMPLATE = app

SRCPATH = ../../../src

INCLUDEPATH = \
    $${SRCPATH} \

SOURCES += \
    createtaskdlgtest.cpp \

HEADERS += \
    $${SRCPATH}/dialogs/createtaskdlg.h \

SOURCES += \
    $${SRCPATH}/dialogs/createtaskdlg.cpp \

FORMS += \
    $${SRCPATH}/dialogs/createtaskdlg.ui \
