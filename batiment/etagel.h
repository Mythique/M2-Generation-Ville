#ifndef ETAGEL_H
#define ETAGEL_H
#include "batiment.h"
class EtageL:public Batiment
{
public:
    EtageL(const Polyangle & p, float h, float hE,int hm,int sm,float am):Batiment(p,h, hE, hm,sm,am){}
    Mesh generate() const;
};
#endif // ETAGEL_H
