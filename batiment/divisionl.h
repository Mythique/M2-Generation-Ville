#ifndef DIVISIOBL_H
#define DIVISIOBL_H
#include "batiment.h"
class DivisionL:public Batiment
{
public:
    DivisionL(const Polyangle & p, float h, float hE,int hm,int sm,float am):Batiment(p,h, hE, hm,sm,am){}
    Mesh generate() const;
};

#endif // DIVISIOBL_H
