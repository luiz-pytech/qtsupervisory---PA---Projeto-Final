QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtTcpClient
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        plotter.cpp

HEADERS  += mainwindow.h \
    plotter.h

FORMS    += mainwindow.ui
