#ifndef JOINTURE_H
#define JOINTURE_H
#include "batiment.h"
class Jointure:public Batiment
{
public:
    Jointure(const Polyangle & p, float h, float hE,int hm,int sm,float am):Batiment(p,h, hE, hm,sm,am){}
    Mesh generate() const;
};

#endif // JOINTURE_H
