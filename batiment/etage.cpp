#include "etage.h"
#include <iostream>
#include "mathutils.h"
#include "toit.h"
#include "toitplat.h"
#include "polyanglehauteur.h"
#include "meshbuilder.h"

Etage::Etage()
{

}

Mesh Etage::generate() const
{
    Polyangle baseShrinked = base.shrink(base.plusPetitCote()/10);

    QVector<PolyangleHauteur> polyangles;
    polyangles << PolyangleHauteur(baseShrinked, hauteur)
               << PolyangleHauteur(baseShrinked, hauteur + hauteurEtage/10)
               << PolyangleHauteur(base, hauteur + hauteurEtage/10)
               << PolyangleHauteur(base, hauteur + hauteurEtage);

    MeshBuilder mb;
    Mesh etageMesh = mb.generationPolyanglesRelies(polyangles);

    double rand = MathUtils::random(0.0, 1.0);
    if (rand < 0.1)
    {
        double rand2 = MathUtils::random(0.0, 1.0);
        if (rand2 < 0.5)
        {
            // Toit
            Toit toit = Toit(base, hauteur + hauteurEtage, hauteurEtage / 2);
            etageMesh.merge(toit.generate());
            return etageMesh;
        }
        else
        {
            // Toit Plat
            ToitPlat toitPlat = ToitPlat(base, hauteur + hauteurEtage, hauteurEtage / 4);
            etageMesh.merge(toitPlat.generate());
            return etageMesh;
        }
    }
    else
    {
        // Etage
        double rand2 = MathUtils::random(0.0, 1.0);
        if (rand2 < 0.5)
        {
            Etage etageSup = Etage(base, hauteur + hauteurEtage, hauteurEtage);
            etageMesh.merge(etageSup.generate());
            return etageMesh;
        }
        else
        {
            // Plus petit
            Etage etageSup = Etage(base.shrink(base.plusPetitCote()/10), hauteur + hauteurEtage, hauteurEtage);
            etageMesh.merge(etageSup.generate());
            return etageMesh;
        }
    }
}

