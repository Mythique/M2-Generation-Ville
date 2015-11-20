#ifndef JOINTUREL_H
#define JOINTUREL_H
#include "batiment.h"
class JointureL:public Batiment
{
private :
    Polyangle poly1;
    Polyangle poly2;
    Polyangle poly3;

public:
    JointureL(const Polyangle & p, float h, float hE,int hm,int sm,float am, Polyangle p1, Polyangle p2, Polyangle p3);
    JointureL(const Polyangle & p, float h, float hE,int hm,int sm,float am):Batiment(p,h, hE, hm,sm,am){}
    Mesh generate() const;
    Polyangle getPoly1() const;
    void setPoly1(const Polyangle &value);
    Polyangle getPoly2() const;
    void setPoly2(const Polyangle &value);
    Polyangle getPoly3() const;
    void setPoly3(const Polyangle &value);
};

#endif // JOINTUREL_H
