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
    batiment/batiment.cpp \
    polyangle.cpp \
    droite.cpp \
    batiment/toit.cpp \
    batiment/etage.cpp \
    plan/route.cpp \
    plan/plan.cpp \
    plan/quartier.cpp \
    batiment/rezdechaussee.cpp \
    batiment/toitplat.cpp \
    batiment/toitresidentiel.cpp \
    batiment/etageresidentiel.cpp \
    batiment/petitetageresidentiel.cpp \
    batiment/cheminee.cpp \
    batiment/rezdechausseebusiness.cpp \
    batiment/rezdechausseeresidentiel.cpp \
    batiment/etagebusiness.cpp \
    batiment/petitetagebusiness.cpp \
    batiment/division.cpp \
    batiment/jointure.cpp \
    batiment/etagel.cpp \
    batiment/divisionl.cpp \
    batiment/jointurel.cpp \
    batiment/toitbusiness.cpp \
    batiment/antenne.cpp \
    batiment/toitbordure.cpp \
    polyanglehauteur.cpp \
    batiment/doubleetagebusiness.cpp \
    plan/citycenter.cpp \
    batiment/multitoit.cpp \
    batiment/toitantenne.cpp

HEADERS += \
    mathutils.h \
    matrix3.h \
    meshbuilder.h \
    vector2d.h \
    vector3d.h \
    mesh.h \
    generateur.h \
    plan/parcelle.h \
    batiment/batiment.h \
    polyangle.h \
    droite.h \
    batiment/toit.h \
    batiment/etage.h \
    plan/route.h \
    plan/plan.h \
    plan/quartier.h \
    batiment/rezdechaussee.h \
    batiment/toitplat.h \
    batiment/toitresidentiel.h \
    batiment/etageresidentiel.h \
    batiment/petitetageresidentiel.h \
    batiment/cheminee.h \
    batiment/rezdechausseebusiness.h \
    batiment/rezdechausseeresidentiel.h \
    batiment/etagebusiness.h \
    batiment/petitetagebusiness.h \
    batiment/division.h \
    batiment/jointure.h \
    batiment/etagel.h \
    batiment/divisionl.h \
    batiment/jointurel.h \
    batiment/toitbusiness.h \
    batiment/antenne.h \
    batiment/toitbordure.h \
    polyanglehauteur.h \
    batiment/doubleetagebusiness.h \
    plan/citycenter.h \
    batiment/multitoit.h \
    batiment/toitantenne.h

