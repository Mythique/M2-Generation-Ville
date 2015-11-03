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
    plan/parcelle.cpp \
    batiment.cpp \
    triangle.cpp \
    polyangle.cpp \
    droite.cpp \
    batiment/toit.cpp \
    batiment/etage.cpp \
    plan/route.cpp \
    plan/plan.cpp \
    plan/quartier.cpp

HEADERS += \
    mathutils.h \
    matrix3.h \
    meshbuilder.h \
    vector2d.h \
    vector3d.h \
    mesh.h \
    generateur.h \
    plan/parcelle.h \
    batiment.h \
    triangle.h \
    polyangle.h \
    droite.h \
    batiment/toit.h \
    batiment/etage.h \
    plan/route.h \
    plan/plan.h \
    plan/quartier.h

