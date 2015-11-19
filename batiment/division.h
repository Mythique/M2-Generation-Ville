#ifndef DIVISION_H
#define DIVISION_H
#include "batiment.h"
class Division:public Batiment
{
private :
    Polyangle poly1;
    Polyangle poly2;
public:
    Division(const Polyangle & p, float h, float hE,int hm,int sm,float am):Batiment(p,h, hE, hm,sm,am){}
    Mesh generate() const;
};

#endif // DIVISION_H
