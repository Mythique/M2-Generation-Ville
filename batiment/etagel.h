#ifndef ETAGEL_H
#define ETAGEL_H
#include "batiment.h"
class EtageL:public Batiment
{
private:
    Polyangle poly1;
    Polyangle poly2;
    Polyangle poly3;

public:
    EtageL(const Polyangle & p, float h, float hE,int hm,int sm,float am, Polyangle p1, Polyangle p2, Polyangle p3):Batiment(p,h, hE, hm,sm,am), poly1(p1), poly2(p2), poly3(p3){}
    EtageL(const Polyangle & p, float h, float hE,int hm,int sm,float am);
    Mesh generate() const;
    Polyangle getPoly1() const;
    void setPoly1(const Polyangle &value);
    Polyangle getPoly2() const;
    void setPoly2(const Polyangle &value);
    Polyangle getPoly3() const;
    void setPoly3(const Polyangle &value);
};
#endif // ETAGEL_H
