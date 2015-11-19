#include "etageresidentiel.h"
#include "toitresidentiel.h"
#include "petitetageresidentiel.h"
#include "../meshbuilder.h"

Mesh EtageResidentiel::generate() const
{

    MeshBuilder mb;
    Mesh etageMesh = mb.generationEtage(this);

    QVector<std::pair<Batiment*,int>> bats;

    ToitResidentiel tr(base,hauteur+hauteurEtage,hauteurEtage,hMax-1,shrinkMax,aireMin);
    PetitEtageResidentiel per(base.shrink(base.plusPetitCote()/10),hauteur+hauteurEtage,hauteurEtage,hMax-1,shrinkMax-1,aireMin);
    EtageResidentiel er(base,hauteur+hauteurEtage,hauteurEtage,hMax-1,shrinkMax,aireMin);
    bats << std::make_pair(&tr,5);
    if(hMax>1){
        bats << std::make_pair(&er,25);

        if(shrinkMax>0&&aireMin<base.area() && base.plusPetitCote() > 10){

            bats << std::make_pair(&per,10);
        }
    }
    etageMesh.merge(Batiment::getRandomBatiment(bats)->generate());
    return etageMesh;
}
