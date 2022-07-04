QT += testlib widgets
TEMPLATE = app

SRCPATH = ../../../src

INCLUDEPATH = \
    $${SRCPATH} \

SOURCES += \
    createprojectdlgtest.cpp \

HEADERS += \
    $${SRCPATH}/dialogs/createprojectdlg.h \
    $${SRCPATH}/models/projectcollection.h \

SOURCES += \
    $${SRCPATH}/dialogs/createprojectdlg.cpp \
    $${SRCPATH}/models/projectcollection.cpp \

FORMS += \
    $${SRCPATH}/dialogs/createprojectdlg.ui \

DEFINES += IGNORE_DIALOG
