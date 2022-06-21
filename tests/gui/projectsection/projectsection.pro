QT += testlib widgets
TEMPLATE = app

SRCPATH = ../../../src

INCLUDEPATH = \
    $${SRCPATH} \

SOURCES += \
    projectsectiontest.cpp \

HEADERS += \
    $${SRCPATH}/gui/projectsection.h \
    $${SRCPATH}/gui/projecttableview.h \

SOURCES += \
    $${SRCPATH}/gui/projectsection.cpp \
    $${SRCPATH}/gui/projecttableview.cpp \

FORMS += \
    $${SRCPATH}/gui/projectsection.ui \
