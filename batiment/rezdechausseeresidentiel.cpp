#include "rezdechausseeresidentiel.h"
#include "toitresidentiel.h"
#include "etageresidentiel.h"
#include "petitetageresidentiel.h"
#include "../meshbuilder.h"

Mesh RezDeChausseeResidentiel::generate() const
{
    if(aireMin>base.area())
        return Mesh();

    QVector<PolyangleHauteur> polyangles;
    polyangles << PolyangleHauteur(base, hauteur)
               << PolyangleHauteur(base, hauteur + hauteurEtage);

    MeshBuilder mb;
    Mesh rdcMesh = mb.generationPolyanglesRelies(polyangles);

    QVector<std::pair<Batiment*,int>> bats;

    ToitResidentiel tr(base,hauteur+hauteurEtage,hauteurEtage,hMax-1,shrinkMax,aireMin);
    PetitEtageResidentiel per(base.shrink(base.plusPetitCote()/10),hauteur+hauteurEtage,hauteurEtage,hMax-1,shrinkMax-1,aireMin);
    EtageResidentiel er(base,hauteur+hauteurEtage,hauteurEtage,hMax-1,shrinkMax,aireMin);
    bats << std::make_pair(&tr,5);
    if(hMax>1){
        bats << std::make_pair(&er,50);

        if(shrinkMax>0)
            bats << std::make_pair(&per,10);
        }

    rdcMesh.merge(Batiment::getRandomBatiment(bats)->generate());
    return rdcMesh;
}
