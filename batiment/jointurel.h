#ifndef JOINTUREL_H
#define JOINTUREL_H
#include "batiment.h"
class JointureL:public Batiment
{
public:
    JointureL(int hm,int sm,float am):Batiment(hm,sm,am){}
    Mesh generate() const;
};

#endif // JOINTUREL_H
