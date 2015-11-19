#ifndef ETAGEBUSINESS_H
#define ETAGEBUSINESS_H
#include "batiment.h"
#include "batiment.h"
#include "vector3d.h"
#include "mesh.h"
#include "polyangle.h"

class EtageBusiness:public Batiment
{

public:
    EtageBusiness(const Polyangle & p, float h, float hE,int hm,int sm,float am):Batiment(p,h, hE, hm,sm,am)
    {

    }
    Mesh generate() const;

};

#endif // ETAGEBUSINESS_H
