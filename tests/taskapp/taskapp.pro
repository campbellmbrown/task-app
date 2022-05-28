QT += testlib widgets
TEMPLATE = app

SRCPATH = ../../src

INCLUDEPATH = \
    $${SRCPATH} \

SOURCES += \
    taskapptest.cpp \

HEADERS += \
    $${SRCPATH}/taskapp.h \

SOURCES += \
    $${SRCPATH}/taskapp.cpp \

FORMS += \
    $${SRCPATH}/taskapp.ui \
