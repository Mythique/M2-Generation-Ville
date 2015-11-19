#ifndef DOUBLEETAGEBUSINESS_H
#define DOUBLEETAGEBUSINESS_H
#include "batiment.h"
#include "vector3d.h"
#include "mesh.h"
#include "polyangle.h"


class DoubleEtageBusiness:public Batiment
{
public:
    DoubleEtageBusiness(const Polyangle & p, float h, float hE,int hm,int sm,float am):Batiment(p,h, hE, hm,sm,am){}
    Mesh generate() const;
};

#endif // DOUBLEETAGEBUSINESS_H
