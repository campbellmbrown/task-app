TARGET = taskapp
TEMPLATE = app

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SRCPATH = .

INCLUDEPATH = \
    $${SRCPATH} \

HEADERS += \
    $${SRCPATH}/gui/detailsview.h \
    $${SRCPATH}/gui/taskapp.h \
    $${SRCPATH}/gui/tasklistview.h \

SOURCES += \
    $${SRCPATH}/gui/detailsview.cpp \
    $${SRCPATH}/gui/taskapp.cpp \
    $${SRCPATH}/gui/tasklistview.cpp \
    $${SRCPATH}/main.cpp \

FORMS += \
    $${SRCPATH}/gui/detailsview.ui \
    $${SRCPATH}/gui/taskapp.ui \
    $${SRCPATH}/gui/tasklistview.ui \

RESOURCES += rc/taskapp.qrc
