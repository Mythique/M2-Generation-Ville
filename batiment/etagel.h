#ifndef ETAGEL_H
#define ETAGEL_H
#include "batiment.h"
class EtageL:public Batiment
{
public:
    EtageL(int hm,int sm,float am):Batiment(hm,sm,am){}
    Mesh generate() const;
};
#endif // ETAGEL_H
