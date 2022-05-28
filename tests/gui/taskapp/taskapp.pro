QT += testlib widgets
TEMPLATE = app

SRCPATH = ../../src

INCLUDEPATH = \
    $${SRCPATH} \

SOURCES += \
    taskapptest.cpp \

HEADERS += \
    $${SRCPATH}/gui/detailsview.h \
    $${SRCPATH}/gui/taskapp.h \
    $${SRCPATH}/gui/tasklistview.h \

SOURCES += \
    $${SRCPATH}/gui/detailsview.cpp \
    $${SRCPATH}/gui/taskapp.cpp \
    $${SRCPATH}/gui/tasklistview.cpp \

FORMS += \
    $${SRCPATH}/gui/detailsview.ui \
    $${SRCPATH}/gui/taskapp.ui \
    $${SRCPATH}/gui/tasklistview.ui \
