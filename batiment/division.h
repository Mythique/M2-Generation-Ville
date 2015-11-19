#ifndef DIVISION_H
#define DIVISION_H
#include "batiment.h"
class Division:public Batiment
{
private :
    Polyangle poly1;
    Polyangle poly2;
public:
    Division(const Polyangle & p, float h, float hE,int hm,int sm,float am);
    Division(const Polyangle & p, float h, float hE,int hm,int sm,float am, const Polyangle & p1, const Polyangle & p2):Batiment(p,h, hE, hm,sm,am), poly1(p1), poly2(p2){}
    Mesh generate() const;
    Polyangle getPoly1() const;
    void setPoly1(const Polyangle &value);
    Polyangle getPoly2() const;
    void setPoly2(const Polyangle &value);
};

#endif // DIVISION_H
