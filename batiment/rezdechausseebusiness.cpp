#include "rezdechausseebusiness.h"
#include "etagebusiness.h"
#include "polyanglehauteur.h"
#include "toitbusiness.h"
#include "petitetagebusiness.h"
#include "meshbuilder.h"


Mesh RezDeChausseeBusiness::generate() const
{
    if(base.area() > aireMin)
    {
        QVector<PolyangleHauteur> polyangles;
        polyangles << PolyangleHauteur(base, hauteur)
                   << PolyangleHauteur(base, hauteur + hauteurEtage);

        MeshBuilder mb;
        Mesh rdcMesh = mb.generationPolyanglesRelies(polyangles);
        QVector<std::pair<Batiment*,int>> bats;

        ToitBusiness tb(base, hauteur, hauteurEtage, hMax, shrinkMax, aireMin);
        EtageBusiness eb(base, hauteur, hauteurEtage, hMax-1, shrinkMax, aireMin);
        PetitEtageBusiness peb(base, hauteur, hauteurEtage, hMax-1, shrinkMax-1, aireMin);
        bats.append(std::make_pair(&tb, 10));

        if(hMax > 1)
        {
            std::make_pair(&eb, 50);
            if(shrinkMax > 0)
            {
                bats.append(std::make_pair(&peb, 20));
            }
        }

        rdcMesh.merge(getRandomBatiment(bats)->generate());
        return rdcMesh;
    }
    else
    {
        return Mesh();
    }

}
