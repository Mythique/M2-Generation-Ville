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
    MeshBuilder mb;
    Mesh etageMesh = mb.generationEtage(this);


    if(hMax > 0 && shrinkMax > 0 && aireMin<base.area())
    {
        DoubleEtageBusiness deb(base, hauteur+hauteurEtage, hauteurEtage, hMax-1, shrinkMax-1, aireMin);
        etageMesh.merge(deb.generate());

    }
    return etageMesh;
}

