#include "petitetagebusiness.h"
#include "toitbusiness.h"
#include "petitetagebusiness.h"
#include "etagebusiness.h"
#include "division.h"
#include "meshbuilder.h"

Mesh PetitEtageBusiness::generate() const
{
        MeshBuilder mb;
        Mesh pebMesh = mb.generationEtage(this);
        QVector<std::pair<Batiment*,int>> bats;

        ToitBusiness tb(base, hauteur+hauteurEtage, hauteurEtage, hMax, shrinkMax, aireMin);
        EtageBusiness eb(base, hauteur+hauteurEtage, hauteurEtage, hMax-1, shrinkMax, aireMin);
        Division d(base, hauteur+hauteurEtage, hauteurEtage, hMax-1, shrinkMax-1, aireMin);
        bats.append(std::make_pair(&tb, 2));

        if(hMax > 1)
        {
            bats.append(std::make_pair(&eb, 70));
            if(shrinkMax > 0 && d.getPoly1().area()>aireMin && d.getPoly2().area() > aireMin)
            {
                bats.append(std::make_pair(&d, 10));
            }
        }

        pebMesh.merge(getRandomBatiment(bats)->generate());
    return pebMesh;
}
