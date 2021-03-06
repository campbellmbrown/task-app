TARGET = taskapp
TEMPLATE = app

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    ./dialogs/createprojectdlg.h \
    ./dialogs/createtaskdlg.h \
    ./gui/projectdetailsection.h \
    ./gui/projectsection.h \
    ./gui/projecttablemodel.h \
    ./gui/projecttableview.h \
    ./gui/taskapp.h \
    ./gui/taskdetailsection.h \
    ./gui/tasksection.h \
    ./gui/tasktablemodel.h \
    ./gui/tasktableview.h \
    ./models/priority.h \
    ./models/projectcollection.h \

SOURCES += \
    ./dialogs/createprojectdlg.cpp \
    ./dialogs/createtaskdlg.cpp \
    ./gui/projectdetailsection.cpp \
    ./gui/projectsection.cpp \
    ./gui/projecttablemodel.cpp \
    ./gui/projecttableview.cpp \
    ./gui/taskapp.cpp \
    ./gui/taskdetailsection.cpp \
    ./gui/tasksection.cpp \
    ./gui/tasktablemodel.cpp \
    ./gui/tasktableview.cpp \
    ./main.cpp \
    ./models/priority.cpp \
    ./models/projectcollection.cpp \

FORMS += \
    ./dialogs/createprojectdlg.ui \
    ./dialogs/createtaskdlg.ui \
    ./gui/projectdetailsection.ui \
    ./gui/projectsection.ui \
    ./gui/taskapp.ui \
    ./gui/taskdetailsection.ui \
    ./gui/tasksection.ui \

RESOURCES += rc/taskapp.qrc
