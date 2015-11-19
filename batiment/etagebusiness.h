#ifndef ETAGEBUSINESS_H
#define ETAGEBUSINESS_H
#include "batiment.h"

class EtageBusiness:public Batiment
{
public:
    EtageBusiness(int hm,int sm,float am):Batiment(hm,sm,am){}
    Mesh generate() const;
};

#endif // ETAGEBUSINESS_H
