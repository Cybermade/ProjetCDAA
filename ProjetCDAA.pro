QT += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    data/contactmodel.cpp \
    data/export.cpp \
    data/interactionmodel.cpp \
    data/todomodel.cpp \
    logic/contact.cpp \
    logic/contactsmanagement.cpp \
    logic/currenttime.cpp \
    logic/interaction.cpp \
    logic/interactionHandler.cpp \
    logic/todo.cpp \
    data/storagehandler.cpp \
    gui/mainwindow.cpp \
    main.cpp

HEADERS += \
    data/contactmodel.h \
    data/export.h \
    data/interactionmodel.h \
    data/todomodel.h \
    logic/contact.h \
    logic/contactsmanagement.h \
    logic/currenttime.h \
    logic/interaction.h \
    logic/interactionHandler.h \
    logic/todo.h \
    data/storagehandler.h \
    gui/mainwindow.h

FORMS += \
    gui/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    .gitignore
