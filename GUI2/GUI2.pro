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
    model.cpp \
    gamecontroller.cpp \
    gamescreenview.cpp \
    usernamebutton.cpp \
    items/caritem.cpp \
    items/coinitem.cpp \
    items/numberitem.cpp \
    items/winlabelitem.cpp \
    windows/recordwindow.cpp \
    windows/mainmenuwindow.cpp \
    windows/userchoicewindow.cpp \
    windows/registrationwindow.cpp \

HEADERS += \
    main.h \
    model.h \
    gamecontroller.h \
    gamescreenview.h \
    usernamebutton.h \
    items/caritem.h \
    items/coinitem.h \
    items/numberitem.h \
    items/winlabelitem.h \
    windows/recordwindow.h \
    windows/mainmenuwindow.h \
    windows/userchoicewindow.h \
    windows/registrationwindow.h \

FORMS += \
    windows/recordwindow.ui \
    windows/mainmenuwindow.ui \
    windows/userchoicewindow.ui \
    windows/registrationwindow.ui \

RESOURCES += \
    gameresources.qrc

DISTFILES +=
