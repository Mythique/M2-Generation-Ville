#ifndef MULTITOIT_H
#define MULTITOIT_H
#include "batiment.h"

class MultiToit:public Batiment
{
   private:
    QVector<Polyangle> poly;

public:
    MultiToit(const Polyangle & p, float h, float hE,int hm,int sm,float am,QVector<Polyangle> ps):Batiment(p,h, hE, hm,sm,am),poly(ps){}
    Mesh generate() const;

};
#endif // MULTITOIT_H
