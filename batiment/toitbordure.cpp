#include "toitbordure.h"
#include "polyanglehauteur.h"
#include "meshbuilder.h"

ToitBordure::ToitBordure()
{

}

Mesh ToitBordure::generate() const
{
    Polyangle baseShrinkedBord = base.shrink(base.plusPetitCote()/10);

    QVector<PolyangleHauteur> polyangles;
    polyangles << PolyangleHauteur(base, hauteur)
               << PolyangleHauteur(base, hauteur + hauteurToit)
               << PolyangleHauteur(baseShrinkedBord, hauteur + hauteurToit)
               << PolyangleHauteur(baseShrinkedBord, hauteur + hauteurToit / 8);

    MeshBuilder mb;
    return mb.generationPolyanglesRelies(polyangles);
}
