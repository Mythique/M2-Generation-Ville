#ifndef DOUBLETOIT_H
#define DOUBLETOIT_H
#include "batiment.h"

class DoubleToit:public Batiment
{
   private:
    Polyangle poly1;
    Polyangle poly2;

public:
    ToitBusiness(const Polyangle & p, float h, float hE,int hm,int sm,float am,Polyangle p1,Polyangle p2):Batiment(p,h, hE, hm,sm,am),poly1(p1),poly2(p2){}
    Mesh generate() const;

}
#endif // DOUBLETOIT_H
