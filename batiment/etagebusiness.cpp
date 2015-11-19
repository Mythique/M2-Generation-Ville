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
    //std::cout << base.getLesPoints().size() << std::endl;
    Polyangle baseShrinked = base.shrink(base.plusPetitCote()/10);
    QVector<PolyangleHauteur> polyangles;
    polyangles << PolyangleHauteur(baseShrinked, hauteur)
               << PolyangleHauteur(baseShrinked, hauteur + hauteurEtage/10)
               << PolyangleHauteur(base, hauteur + hauteurEtage/10)
               << PolyangleHauteur(base, hauteur + hauteurEtage);
    MeshBuilder mb;
    Mesh etageMesh = mb.generationPolyanglesRelies(polyangles);

    //std::cout << hMax << std::endl;
    //std::cout << shrinkMax << std::endl;
    //std::cout << base.getLesPoints().size() << std::endl;
    if(hMax > 0 && shrinkMax > 0 && aireMin<base.area())
    {
        //std::cout <<" fait un log la" << std::endl;
        DoubleEtageBusiness deb(base, hauteur+hauteurEtage, hauteurEtage, hMax-1, shrinkMax-1, aireMin);
        etageMesh.merge(deb.generate());

    }


    return etageMesh;
}

