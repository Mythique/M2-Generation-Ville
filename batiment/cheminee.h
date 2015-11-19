#ifndef CHEMINEE_H
#define CHEMINEE_H
#include "batiment.h"

class Cheminee:public Batiment
{
public:
    Cheminee(int hm,int sm,float am):Batiment(hm,sm,am){}
    Mesh generate() const;
};

#endif // CHEMINEE_H
