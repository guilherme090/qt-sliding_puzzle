QT += widgets core gui

SOURCES = main.cpp \
    button.cpp \
    jogo.cpp \
    pixmap.cpp \
    view.cpp

RESOURCES = slidingpuzzle.qrc
# install
TARGET = app

HEADERS += \
    resources.h jogo.h
