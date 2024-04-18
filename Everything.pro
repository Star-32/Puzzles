QT       += core gui
QT       += multimedia
QT       += webenginewidgets
QT       += texttospeech

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    barrier.cpp \
    block.cpp \
    browser.cpp \
    csp274.cpp \
    cspkwants.cpp \
    cspyl.cpp \
    empty.cpp \
    enteranswer.cpp \
    game1.cpp \
    gamea.cpp \
    gamearea.cpp \
    gamelose.cpp \
    gamewin.cpp \
    getname.cpp \
    lose.cpp \
    main.cpp \
    mainwindow.cpp \
    mediaplayer.cpp \
    noi274.cpp \
    noikwants.cpp \
    noip274.cpp \
    noipkwants.cpp \
    noipyl.cpp \
    noiyl.cpp \
    swebengineview.cpp \
    win.cpp

HEADERS += \
    barrier.h \
    block.h \
    browser.h \
    csp274.h \
    cspkwants.h \
    cspyl.h \
    empty.h \
    enteranswer.h \
    game1.h \
    gamea.h \
    gamearea.h \
    gamelose.h \
    gamewin.h \
    getname.h \
    lose.h \
    mainwindow.h \
    mediaplayer.h \
    noi274.h \
    noikwants.h \
    noip274.h \
    noipkwants.h \
    noipyl.h \
    noiyl.h \
    swebengineview.h \
    win.h

FORMS += \
    browser.ui \
    csp274.ui \
    cspkwants.ui \
    cspyl.ui \
    empty.ui \
    enteranswer.ui \
    game1.ui \
    gamea.ui \
    gamearea.ui \
    gamelose.ui \
    gamewin.ui \
    getname.ui \
    lose.ui \
    mainwindow.ui \
    mediaplayer.ui \
    noi274.ui \
    noikwants.ui \
    noip274.ui \
    noipkwants.ui \
    noipyl.ui \
    noiyl.ui \
    swebengineview.ui \
    win.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    cactus.qrc \
    songs.qrc

msvc{
    QMAKE_CFLAGS += /utf-8
    QMAKE_CXXFLAGS += /utf-8
}
