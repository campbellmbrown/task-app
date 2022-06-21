TARGET = taskapp
TEMPLATE = app

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    ./dialogs/createtaskdlg.h \
    ./gui/taskdetailsection.h \
    ./gui/taskapp.h \
    ./gui/tasksection.h \
    ./gui/tasktablemodel.h \
    ./gui/tasktableview.h \
    ./models/priority.h \
    ./models/projectscollection.h \

SOURCES += \
    ./dialogs/createtaskdlg.cpp \
    ./gui/taskdetailsection.cpp \
    ./gui/taskapp.cpp \
    ./gui/tasksection.cpp \
    ./gui/tasktablemodel.cpp \
    ./gui/tasktableview.cpp \
    ./main.cpp \
    ./models/priority.cpp \
    ./models/projectscollection.cpp \

FORMS += \
    ./dialogs/createtaskdlg.ui \
    ./gui/taskdetailsection.ui \
    ./gui/taskapp.ui \
    ./gui/tasksection.ui \

RESOURCES += rc/taskapp.qrc
