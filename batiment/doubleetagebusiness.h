#ifndef DOUBLEETAGEBUSINESS_H
#define DOUBLEETAGEBUSINESS_H
#include "batiment.h"
#include "vector3d.h"
#include "mesh.h"
#include "polyangle.h"


class DoubleEtageBusiness:public Batiment
{
private:
    Polyangle poly1;
    Polyangle poly2;

public:
    DoubleEtageBusiness(const Polyangle & p, float h, float hE,int hm,int sm,float am);
    Mesh generate() const;
    Polyangle getPoly1() const;
    void setPoly1(const Polyangle &value);
    Polyangle getPoly2() const;
    void setPoly2(const Polyangle &value);
};

#endif // DOUBLEETAGEBUSINESS_H
