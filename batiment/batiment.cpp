#include "batiment.h"
#include "../mathutils.h"

int Batiment::getHMax() const
{
    return hMax;
}

int Batiment::getShrinkMax() const
{
    return shrinkMax;
}

float Batiment::getAireMin() const
{
    return aireMin;
}

Polyangle Batiment::getBase() const
{
    return base;
}

float Batiment::getHauteur() const
{
    return hauteur;
}

float Batiment::getHauteurEtage() const
{
    return hauteurEtage;
}

Batiment::Batiment() {}

Batiment::Batiment(const Polyangle &p, float h, float hE, int hM, int sM, float aM) : base(p), hauteur(h), hauteurEtage(hE),hMax(hM), shrinkMax(sM), aireMin(aM)
{

}

Batiment* Batiment::getRandomBatiment(const QVector<std::pair<Batiment*,int>>& bats)
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

