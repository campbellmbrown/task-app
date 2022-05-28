TARGET = taskapp
TEMPLATE = app

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    ./gui/detailsview.h \
    ./gui/taskapp.h \
    ./gui/tasklistview.h \

SOURCES += \
    ./gui/detailsview.cpp \
    ./gui/taskapp.cpp \
    ./gui/tasklistview.cpp \
    ./main.cpp \

FORMS += \
    ./gui/detailsview.ui \
    ./gui/taskapp.ui \
    ./gui/tasklistview.ui \

RESOURCES += rc/taskapp.qrc
