#-------------------------------------------------
#
# Project created by QtCreator 2014-09-30T15:45:27
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Ninjutsew
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    viewport.cpp \
    camera.cpp \
    vec3utils.cpp \
    scopedmatrixmode.cpp \
    graphicscontext.cpp \
    colorutils.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    viewport.h \
    camera.h \
    vec3utils.h \
    scopedmatrixmode.h \
    glmatrixmode.h \
    graphicscontext.h \
    colorutils.h

FORMS    += mainwindow.ui
