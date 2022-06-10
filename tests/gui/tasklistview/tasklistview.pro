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
    $${SRCPATH}/gui/tasktablemodel.h \
    $${SRCPATH}/gui/tasktableview.h \
    $${SRCPATH}/models/projectscollection.h \

SOURCES += \
    $${SRCPATH}/dialogs/createtaskdlg.cpp \
    $${SRCPATH}/gui/tasklistview.cpp \
    $${SRCPATH}/gui/tasktablemodel.cpp \
    $${SRCPATH}/gui/tasktableview.cpp \
    $${SRCPATH}/models/projectscollection.cpp \

FORMS += \
    $${SRCPATH}/dialogs/createtaskdlg.ui \
    $${SRCPATH}/gui/tasklistview.ui \
