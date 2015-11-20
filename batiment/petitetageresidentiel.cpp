#include "petitetageresidentiel.h"
#include "toitresidentiel.h"
#include "etageresidentiel.h"
#include "../meshbuilder.h"
Mesh PetitEtageResidentiel::generate() const
{

    MeshBuilder mb;
    Mesh etageMesh = mb.generationEtage(this);

    QVector<std::pair<Batiment*,int>> bats;

    ToitResidentiel tr(base,hauteur+hauteurEtage,hauteurEtage,hMax-1,shrinkMax,aireMin);
    EtageResidentiel er(base,hauteur+hauteurEtage,hauteurEtage,hMax-1,shrinkMax,aireMin);
    bats << std::make_pair(&tr,5);
    if(hMax>1){
        bats << std::make_pair(&er,50);
    }
    etageMesh.merge(Batiment::getRandomBatiment(bats)->generate());
    return etageMesh;
}
