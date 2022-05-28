TARGET = taskapp
TEMPLATE = app

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    ./gui/taskapp.h \

SOURCES += \
    ./gui/taskapp.cpp \
    ./main.cpp \

FORMS += \
    ./gui/taskapp.ui \

RESOURCES += rc/taskapp.qrc
