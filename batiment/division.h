#ifndef DIVISION_H
#define DIVISION_H
#include "batiment.h"
class Division:public Batiment
{
public:
    Division(int hm,int sm,float am):Batiment(hm,sm,am){}
    Mesh generate() const;
};

#endif // DIVISION_H
