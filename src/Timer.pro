TEMPLATE = subdirs
CONFIG += console

#Library targets and depdendencies
SUBDIRS = cppCORE\
        cppGUI\
        Timer

cppGUI.depends = cppCORE
Timer.depends = cppCORE cppGUI
