#ifndef PETITETAGEBUSINESS_H
#define PETITETAGEBUSINESS_H
#include "batiment.h"
class PetitEtageBusiness:public Batiment
{
public:
    PetitEtageBusiness(int hm,int sm,float am):Batiment(hm,sm,am){}
    Mesh generate() const;
};

#endif // PETITETAGEBUSINESS_H
