#include "etagebusiness.h"
#include <iostream>
#include "mathutils.h"
#include "toit.h"
#include "toitplat.h"
#include "polyanglehauteur.h"
#include "meshbuilder.h"
#include "etage.h"
#include "doubleetagebusiness.h"

Mesh EtageBusiness::generate() const
{
    Polyangle baseShrinked = base.shrink(base.plusPetitCote()/10);
    QVector<PolyangleHauteur> polyangles;
    polyangles << PolyangleHauteur(baseShrinked, hauteur)
               << PolyangleHauteur(baseShrinked, hauteur + hauteurEtage/10)
               << PolyangleHauteur(base, hauteur + hauteurEtage/10)
               << PolyangleHauteur(base, hauteur + hauteurEtage);
    MeshBuilder mb;
    Mesh etageMesh = mb.generationPolyanglesRelies(polyangles);


    if(hMax > 0 && shrinkMax > 0 && aireMin<base.area())
    {
        DoubleEtageBusiness deb(base, hauteur+hauteurEtage, hauteurEtage, hMax-1, shrinkMax-1, aireMin);
        etageMesh.merge(deb.generate());

    }
    return etageMesh;
}

