#-------------------------------------------------
#
# Project created by QtCreator 2019-12-19T02:26:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Project225
TEMPLATE = app


SOURCES += main.cpp\
        rbtree.cpp \
    node.cpp \
    mydialog.cpp \
    playdialog.cpp \
    helpdialog.cpp

HEADERS  += rbtree.h \
    node.h \
    mydialog.h \
    playdialog.h \
    helpdialog.h

FORMS    += rbtree.ui \
    mydialog.ui \
    playdialog.ui \
    helpdialog.ui
