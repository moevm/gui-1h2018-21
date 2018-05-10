#-------------------------------------------------
#
# Project created by QtCreator 2018-03-26T17:01:24
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUI2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        registrationwindow.cpp \
    gamecontroller.cpp \
    mainmenuwindow.cpp \
    model.cpp \
    userchoicewindow.cpp \
    gamescreenview.cpp \
    caritem.cpp \
    coinitem.cpp \
    winlabelitem.cpp \
    numberitem.cpp \
    recordwindow.cpp \
    usernamebutton.cpp

HEADERS += \
        registrationwindow.h \
    gamecontroller.h \
    mainmenuwindow.h \
    model.h \
    model.h \
    userchoicewindow.h \
    gamescreenview.h \
    caritem.h \
    coinitem.h \
    winlabelitem.h \
    numberitem.h \
    recordwindow.h \
    usernamebutton.h

FORMS += \
        registrationwindow.ui \
    mainmenuwindow.ui \
    userchoicewindow.ui \
    recordwindow.ui

RESOURCES += \
    gameresources.qrc

DISTFILES +=
