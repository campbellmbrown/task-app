QT += testlib widgets
TEMPLATE = app

SRCPATH = ../../../src

INCLUDEPATH = \
    $${SRCPATH} \

SOURCES += \
    createtaskdlgtest.cpp \

HEADERS += \
    $${SRCPATH}/dialogs/createtaskdlg.h \
    $${SRCPATH}/models/priority.h \
    $${SRCPATH}/models/projectcollection.h \

SOURCES += \
    $${SRCPATH}/dialogs/createtaskdlg.cpp \
    $${SRCPATH}/models/priority.cpp \
    $${SRCPATH}/models/projectcollection.cpp \

FORMS += \
    $${SRCPATH}/dialogs/createtaskdlg.ui \

DEFINES += IGNORE_DIALOG
