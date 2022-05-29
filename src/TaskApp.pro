TARGET = taskapp
TEMPLATE = app

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    ./dialogs/createtaskdlg.h \
    ./gui/detailsview.h \
    ./gui/taskapp.h \
    ./gui/tasklistview.h \

SOURCES += \
    ./dialogs/createtaskdlg.cpp \
    ./gui/detailsview.cpp \
    ./gui/taskapp.cpp \
    ./gui/tasklistview.cpp \
    ./main.cpp \

FORMS += \
    ./dialogs/createtaskdlg.ui \
    ./gui/detailsview.ui \
    ./gui/taskapp.ui \
    ./gui/tasklistview.ui \

RESOURCES += rc/taskapp.qrc
