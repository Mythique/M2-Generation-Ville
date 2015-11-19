#ifndef JOINTURE_H
#define JOINTURE_H
#include "batiment.h"
class Jointure:public Batiment
{
private:
    Polyangle poly1;
    Polyangle poly2;

public:

    Jointure(const Polyangle & p, float h, float hE,int hm,int sm,float am, const Polyangle & p1, const Polyangle & p2);
    Mesh generate() const;
    Polyangle getPoly2() const;
    void setPoly2(const Polyangle &value);
    Polyangle getPoly1() const;
    void setPoly1(const Polyangle &value);
};

#endif // JOINTURE_H
