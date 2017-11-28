TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    source.cpp

HEADERS += \
    random.hpp \
    header.hpp

QMAKE_CXXFLAGS += -pedantic-errors
