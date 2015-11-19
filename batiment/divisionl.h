#ifndef DIVISIOBL_H
#define DIVISIOBL_H
#include "batiment.h"
class DivisionL:public Batiment
{
public:
    DivisionL(int hm,int sm,float am):Batiment(hm,sm,am){}
    Mesh generate() const;
};

#endif // DIVISIOBL_H
