QT += testlib sql
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app
INCLUDEPATH += $$PWD/../Parser
SOURCES +=  \
    ../Parser/OlxQueryBuilder.cpp \
    ../Parser/ZorQueryBuilder.cpp \
    ../Parser/UyBorQueryBuilder.cpp \
    ../Parser/DataBase.cpp \
    TestDataBase.cpp \
    TestOlxQueryBuilder.cpp \
    TestUyBorQueryBuilder.cpp \
    TestZorQueryBuilder.cpp \
    main.cpp

HEADERS += \
    AutoTest.h \
    TestDataBase.h \
    TestOlxQueryBuilder.h \
    TestUyBorQueryBuilder.h \
    TestZorQueryBuilder.h

