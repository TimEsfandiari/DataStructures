TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt


SOURCES += main.cpp \
    Player.cpp \
    Team.cpp \
    Tag.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    Player.h \
    Team.h \
    Tag.h

