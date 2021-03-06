#-------------------------------------------------
#
# Project created by QtCreator 2019-01-24T18:36:10
#
#-------------------------------------------------

QT       -= gui

TARGET = ManagementAlgorithm
TEMPLATE = lib
CONFIG(release,debug|release): conf = release
CONFIG(debug,debug|release): conf = debug
DEFINES += MANAGEMENTALGORITHM_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
algoPath =$$shell_path($$(HOME)/git/AlgorithmSubSystem)

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        managementalgorithm.cpp

HEADERS += \
        managementalgorithm.h \
        managementalgorithm_global.h

INCLUDEPATH += \
        $$algoPath

#LIBS += -L$$algoPath/lib/$$conf -lAlgorithmSubSystem
#DEPENDPATH += $$algoPath/lib/$$conf
#message($$algoPath/lib/$$conf)
#unix {
#    target.path = /usr/lib
#    INSTALLS += target
#}




unix:!macx: LIBS += -L$$PWD/../AlgorithmSubSystem/lib/debug/ -lAlgorithmSubSystem

#INCLUDEPATH += $$PWD/../AlgorithmSubSystem/lib
#DEPENDPATH += $$PWD/../AlgorithmSubSystem/lib

unix:!macx: PRE_TARGETDEPS += $$PWD/../AlgorithmSubSystem/lib/$$conf/libAlgorithmSubSystem.a
