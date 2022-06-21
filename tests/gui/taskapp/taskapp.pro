QT += testlib widgets
TEMPLATE = app

SRCPATH = ../../../src

INCLUDEPATH = \
    $${SRCPATH} \

SOURCES += \
    taskapptest.cpp \

HEADERS += \
    $${SRCPATH}/dialogs/createtaskdlg.h \
    $${SRCPATH}/gui/projectdetailsection.h \
    $${SRCPATH}/gui/projectsection.h \
    $${SRCPATH}/gui/projecttableview.h \
    $${SRCPATH}/gui/taskapp.h \
    $${SRCPATH}/gui/taskdetailsection.h \
    $${SRCPATH}/gui/tasksection.h \
    $${SRCPATH}/gui/tasktablemodel.h \
    $${SRCPATH}/gui/tasktableview.h \
    $${SRCPATH}/models/priority.h \
    $${SRCPATH}/models/projectscollection.h \

SOURCES += \
    $${SRCPATH}/dialogs/createtaskdlg.cpp \
    $${SRCPATH}/gui/projectdetailsection.cpp \
    $${SRCPATH}/gui/projectsection.cpp \
    $${SRCPATH}/gui/projecttableview.cpp \
    $${SRCPATH}/gui/taskapp.cpp \
    $${SRCPATH}/gui/taskdetailsection.cpp \
    $${SRCPATH}/gui/tasksection.cpp \
    $${SRCPATH}/gui/tasktablemodel.cpp \
    $${SRCPATH}/gui/tasktableview.cpp \
    $${SRCPATH}/models/priority.cpp \
    $${SRCPATH}/models/projectscollection.cpp \

FORMS += \
    $${SRCPATH}/dialogs/createtaskdlg.ui \
    $${SRCPATH}/gui/projectdetailsection.ui \
    $${SRCPATH}/gui/projectsection.ui \
    $${SRCPATH}/gui/taskapp.ui \
    $${SRCPATH}/gui/taskdetailsection.ui \
    $${SRCPATH}/gui/tasksection.ui \
