#ifndef ANTENNE_H
#define ANTENNE_H
#include "batiment.h"
class Antenne:public Batiment
{
public:
    Antenne(const Polyangle & p, float h, float hE,int hm,int sm,float am):Batiment(p,h, hE, hm,sm,am){}
    Mesh generate() const;
};
#endif // ANTENNE_H
