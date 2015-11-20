#include "toitbordure.h"
#include "polyanglehauteur.h"
#include "meshbuilder.h"
#include "antenne.h"

ToitBordure::ToitBordure()
{

}

Mesh ToitBordure::generate() const
{
    Polyangle baseShrinkedBord = base.shrink(base.plusPetitCote()/10);
    Polyangle baseShrinkedAntenne = base.shrink(base.plusPetitCote()/2.5);

    QVector<PolyangleHauteur> polyangles;
    polyangles << PolyangleHauteur(base, hauteur)
               << PolyangleHauteur(base, hauteur + hauteurToit)
               << PolyangleHauteur(baseShrinkedBord, hauteur + hauteurToit)
               << PolyangleHauteur(baseShrinkedBord, hauteur);

    Antenne antenne(baseShrinkedAntenne, hauteur, hauteurToit * 10, 0, 0 ,0);

    MeshBuilder mb;
    Mesh toitMesh = mb.generationPolyanglesRelies(polyangles);
    toitMesh.merge(antenne.generate());
    return toitMesh;
}
