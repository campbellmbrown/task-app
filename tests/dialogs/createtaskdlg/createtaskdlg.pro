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
    $${SRCPATH}/models/projectscollection.h \

SOURCES += \
    $${SRCPATH}/dialogs/createtaskdlg.cpp \
    $${SRCPATH}/models/priority.cpp \
    $${SRCPATH}/models/projectscollection.cpp \

FORMS += \
    $${SRCPATH}/dialogs/createtaskdlg.ui \

DEFINES += IGNORE_DIALOG
