#ifndef PETITETAGERESIDENTIEL_H
#define PETITETAGERESIDENTIEL_H
#include "batiment.h"

class PetitEtageResidentiel:public Batiment
{
public:
    PetitEtageResidentiel(int hm,int sm,float am):Batiment(hm,sm,am){}
    Mesh generate() const;
};

#endif // PETITETAGERESIDENTIEL_H
