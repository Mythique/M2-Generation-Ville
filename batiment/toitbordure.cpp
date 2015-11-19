#include "toitbordure.h"
#include "polyanglehauteur.h"
#include "meshbuilder.h"

ToitBordure::ToitBordure()
{

}

Mesh ToitBordure::generate()
{
    Polyangle baseShrinked = base.shrink(base.perimetre()/100);

    QVector<PolyangleHauteur> polyangles;
    polyangles << PolyangleHauteur(base, hauteur)
               << PolyangleHauteur(base, hauteur + hauteurToit)
               << PolyangleHauteur(baseShrinked, hauteur + hauteurToit)
               << PolyangleHauteur(baseShrinked, hauteur);

    MeshBuilder mb;
    return mb.generationPolyanglesRelies(polyangles);
}
