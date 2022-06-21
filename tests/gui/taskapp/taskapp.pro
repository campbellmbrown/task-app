QT += testlib widgets
TEMPLATE = app

SRCPATH = ../../../src

INCLUDEPATH = \
    $${SRCPATH} \

SOURCES += \
    taskapptest.cpp \

HEADERS += \
    $${SRCPATH}/dialogs/createtaskdlg.h \
    $${SRCPATH}/gui/taskdetailsection.h \
    $${SRCPATH}/gui/taskapp.h \
    $${SRCPATH}/gui/tasksection.h \
    $${SRCPATH}/gui/tasktablemodel.h \
    $${SRCPATH}/gui/tasktableview.h \
    $${SRCPATH}/models/priority.h \
    $${SRCPATH}/models/projectscollection.h \

SOURCES += \
    $${SRCPATH}/dialogs/createtaskdlg.cpp \
    $${SRCPATH}/gui/taskdetailsection.cpp \
    $${SRCPATH}/gui/taskapp.cpp \
    $${SRCPATH}/gui/tasksection.cpp \
    $${SRCPATH}/gui/tasktablemodel.cpp \
    $${SRCPATH}/gui/tasktableview.cpp \
    $${SRCPATH}/models/priority.cpp \
    $${SRCPATH}/models/projectscollection.cpp \

FORMS += \
    $${SRCPATH}/dialogs/createtaskdlg.ui \
    $${SRCPATH}/gui/taskdetailsection.ui \
    $${SRCPATH}/gui/taskapp.ui \
    $${SRCPATH}/gui/tasksection.ui \
