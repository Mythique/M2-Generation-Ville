#include "toitplat.h"
#include "polyanglehauteur.h"
#include "meshbuilder.h"

ToitPlat::ToitPlat()
{

}

Mesh ToitPlat::generate() const
{
    Polyangle baseShrinked = base.shrink(base.plusPetitCote()/10);

    QVector<PolyangleHauteur> polyangles;
    polyangles << PolyangleHauteur(base, hauteur)
               << PolyangleHauteur(baseShrinked, hauteur + hauteurToit);

    MeshBuilder mb;
    return mb.generationPolyanglesRelies(polyangles);
}
