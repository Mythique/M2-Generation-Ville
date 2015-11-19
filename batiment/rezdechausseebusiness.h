#ifndef REZDECHAUSSEEBUSINESS_H
#define REZDECHAUSSEEBUSINESS_H
#include "batiment.h"

class RezDeChausseeBusiness:public Batiment
{
public:
    RezDeChausseeBusiness(int hm,int sm,float am):Batiment(hm,sm,am){}
    Mesh generate() const;
};

#endif // REZDECHAUSSEEBUSINESS_H
