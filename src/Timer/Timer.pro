# -------------------------------------------------
# Project created by QtCreator 2010-03-29T13:28:53
# -------------------------------------------------

QT += core widgets gui multimedia

TARGET = Timer
TEMPLATE = app
RC_FILE	 = icon.rc

SOURCES += main.cpp \
    timerwindow.cpp \
    timerpage.cpp \
    stopwatchpage.cpp
HEADERS += timerwindow.h \
    timerpage.h \
    stopwatchpage.h
FORMS += timerwindow.ui \
    timerpage.ui \
    stopwatchpage.ui

#include cppCORE library
INCLUDEPATH += $$PWD/../../src/cppCORE
LIBS += -L$$PWD/../../bin -lcppCORE

#include cppGUI library
INCLUDEPATH += $$PWD/../../src/cppGUI
LIBS += -L$$PWD/../../bin -lcppGUI

#copy EXE to bin folder
DESTDIR = $$PWD/../../bin

RESOURCES += \    
    Timer.qrc
