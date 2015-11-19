#ifndef PETITETAGEBUSINESS_H
#define PETITETAGEBUSINESS_H
#include "batiment.h"
class PetitEtageBusiness:public Batiment
{
public:
    PetitEtageBusiness(const Polyangle & p, float h, float hE,int hm,int sm,float am):Batiment(p,h, hE, hm,sm,am){}
    Mesh generate() const;
};

#endif // PETITETAGEBUSINESS_H
