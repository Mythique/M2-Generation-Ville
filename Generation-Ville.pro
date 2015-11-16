QT += core gui

TARGET = Generation-Ville
CONFIG += console c++11
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
    polyangle.cpp \
    droite.cpp \
    batiment/toit.cpp \
    batiment/etage.cpp \
    plan/route.cpp \
    plan/plan.cpp \
    plan/quartier.cpp \
    batiment/rezdechaussee.cpp \
    batiment/toitplat.cpp \
    batiment/toitbordure.cpp \
    polyanglehauteur.cpp

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
    polyangle.h \
    droite.h \
    batiment/toit.h \
    batiment/etage.h \
    plan/route.h \
    plan/plan.h \
    plan/quartier.h \
    batiment/rezdechaussee.h \
    batiment/toitplat.h \
    batiment/toitbordure.h \
    polyanglehauteur.h

