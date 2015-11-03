QT += core gui

TARGET = Generation-Ville
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    mathutils.cpp \
    matrix3.cpp \
    meshbuilder.cpp \
    vector2d.cpp \
    vector3d.cpp \
    mesh.cpp \
    triangle.cpp \
    polyangle.cpp \
    quadrangle.cpp \
    droite.cpp

HEADERS += \
    mathutils.h \
    matrix3.h \
    meshbuilder.h \
    vector2d.h \
    vector3d.h \
    mesh.h \
    triangle.h \
    polyangle.h \
    quadrangle.h \
    droite.h

