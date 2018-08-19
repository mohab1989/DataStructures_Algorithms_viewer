#-------------------------------------------------
#
# Project created by QtCreator 2016-05-28T15:30:47
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DSA_Visualizer
TEMPLATE = app


SOURCES +=\
        mainwindow.cpp \
    LinkedList/linked_list.cpp \
    create_dsa.cpp


HEADERS  += mainwindow.h \
    LinkedList/linked_list.h \
    create_dsa.h


FORMS    += mainwindow.ui \
    create_dsa.ui
