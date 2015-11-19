#include "batiment.h"
#include "../mathutils.h"

Batiment::Batiment() {}

Batiment::Batiment(int hM, int sM, float aM) : hMax(hM), shrinkMax(sM), aireMax(aM) {}

Batiment* Batiment::getRandomBatiment(QVector<std::pair<Batiment*,int>> bats)
{
    int somme=0;
    for(int i=0;i<bats.size();++i){
        somme+=bats.at(i).second;
    }

    float rand=MathUtils::random(0,somme);

    somme =0;
    for(int i=0;i<bats.size();++i){
        somme+=bats.at(i).second;
        if(rand<somme)
            return bats.at(i).first;
    }
    return nullptr;
}

