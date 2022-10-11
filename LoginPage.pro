QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    changepassworddialog.cpp \
    logindatamanager.cpp \
    loginmanager.cpp \
    main.cpp \
    mainwindow.cpp \
    newpassworddialog.cpp \
    newuserdialog.cpp \
    panelwindow.cpp \
    parserfromtxt.cpp \
    user.cpp \
    userlist.cpp \
    validator.cpp

HEADERS += \
    changepassworddialog.h \
    logindatamanager.h \
    loginmanager.h \
    mainwindow.h \
    newpassworddialog.h \
    newuserdialog.h \
    panelwindow.h \
    parserfromtxt.h \
    user.h \
    userlist.h \
    validator.h

FORMS += \
    changepassworddialog.ui \
    mainwindow.ui \
    newpassworddialog.ui \
    newuserdialog.ui \
    panelwindow.ui \
    userlist.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    users.txt
