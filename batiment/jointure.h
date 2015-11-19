#ifndef JOINTURE_H
#define JOINTURE_H
#include "batiment.h"
class Jointure:public Batiment
{
public:
    Jointure(int hm,int sm,float am):Batiment(hm,sm,am){}
    Mesh generate() const;
};

#endif // JOINTURE_H
