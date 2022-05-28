TARGET = taskapp
TEMPLATE = app

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    ./taskapp.h \

SOURCES += \
    ./main.cpp \
    ./taskapp.cpp \

FORMS += \
    ./taskapp.ui \

RESOURCES += rc/taskapp.qrc
