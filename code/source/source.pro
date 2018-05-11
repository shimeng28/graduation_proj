#-------------------------------------------------
#
# Project created by QtCreator 2018-04-08T20:06:11
#
#-------------------------------------------------

QT       += core gui
QT       += opengl
QT       += serialport


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = source
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp \
    controlpanel.cpp \
    mainwindow.cpp \
    openglwidget.cpp \
    paintcircle.cpp

HEADERS  += \
    controlpanel.h \
    mainwindow.h \
    openglwidget.h \
    paintcircle.h

FORMS    += \
    mainwindow.ui



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/QtXlsxWriter-master/lib/release/ -lQt5Xlsx
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/QtXlsxWriter-master/lib/debug/ -lQt5Xlsx
else:unix: LIBS += -L$$PWD/QtXlsxWriter-master/lib/ -lQt5Xlsx

INCLUDEPATH += $$PWD/QtXlsxWriter-master/include
DEPENDPATH += $$PWD/QtXlsxWriter-master/include
