#ifndef ANTENNE_H
#define ANTENNE_H
#include "batiment.h"
class Antenne:public Batiment
{
public:
    Antenne(int hm,int sm,float am):Batiment(hm,sm,am){}
    Mesh generate() const;
};
#endif // ANTENNE_H
