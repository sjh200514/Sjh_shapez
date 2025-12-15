QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    belt.cpp \
    block.cpp \
    center.cpp \
    circle.cpp \
    cutter.cpp \
    end.cpp \
    fang.cpp \
    gamescene.cpp \
    gold.cpp \
    main.cpp \
    mainscene.cpp \
    miner.cpp \
    rect.cpp \
    rubbish.cpp \
    shengji.cpp \
    shopping.cpp \
    yuan.cpp

HEADERS += \
    belt.h \
    block.h \
    center.h \
    circle.h \
    cutter.h \
    end.h \
    fang.h \
    gamescene.h \
    gold.h \
    mainscene.h \
    miner.h \
    rect.h \
    rubbish.h \
    shengji.h \
    shopping.h \
    yuan.h

FORMS += \
    end.ui \
    gamescene.ui \
    mainscene.ui \
    shengji.ui \
    shopping.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
