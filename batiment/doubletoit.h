#ifndef DOUBLETOIT_H
#define DOUBLETOIT_H
#include "batiment.h"

class DoubleToit:public Batiment
{
   private:
    QVector<Polyangle> poly;

public:
    DoubleToit(const Polyangle & p, float h, float hE,int hm,int sm,float am,QVector<Polyangle> ps):Batiment(p,h, hE, hm,sm,am),poly(ps){}
    Mesh generate() const;

};
#endif // DOUBLETOIT_H
