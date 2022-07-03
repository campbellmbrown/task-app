QT += testlib widgets
TEMPLATE = app

SRCPATH = ../../../src

INCLUDEPATH = \
    $${SRCPATH} \

SOURCES += \
    projectsectiontest.cpp \

HEADERS += \
    $${SRCPATH}/dialogs/createprojectdlg.h \
    $${SRCPATH}/gui/projectsection.h \
    $${SRCPATH}/gui/projecttablemodel.h \
    $${SRCPATH}/gui/projecttableview.h \
    $${SRCPATH}/models/projectcollection.h \

SOURCES += \
    $${SRCPATH}/dialogs/createprojectdlg.cpp \
    $${SRCPATH}/gui/projectsection.cpp \
    $${SRCPATH}/gui/projecttablemodel.cpp \
    $${SRCPATH}/gui/projecttableview.cpp \
    $${SRCPATH}/models/projectcollection.cpp \

FORMS += \
    $${SRCPATH}/dialogs/createprojectdlg.ui \
    $${SRCPATH}/gui/projectsection.ui \
