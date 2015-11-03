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
    generateur.cpp \
    parcelle.cpp \
    batiment.cpp
    triangle.cpp \
    polyangle.cpp \
    quadrangle.cpp

HEADERS += \
    mathutils.h \
    matrix3.h \
    meshbuilder.h \
    vector2d.h \
    vector3d.h \
    mesh.h \
    generateur.h \
    parcelle.h \
    batiment.h
    triangle.h \
    polyangle.h \
    quadrangle.h

