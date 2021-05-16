QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cinema.cpp \
    loser.cpp \
    main.cpp \
    mainwindow.cpp \
    pays.cpp \
    second.cpp \
    sport.cpp \
    third.cpp \
    winner.cpp

HEADERS += \
    cinema.h \
    loser.h \
    mainwindow.h \
    pays.h \
    second.h \
    sport.h \
    third.h \
    winner.h

FORMS += \
    cinema.ui \
    loser.ui \
    mainwindow.ui \
    pays.ui \
    second.ui \
    sport.ui \
    third.ui \
    winner.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../../Desktop/nom femmes sportives françaises.txt
