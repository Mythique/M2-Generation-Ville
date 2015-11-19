#ifndef JOINTUREL_H
#define JOINTUREL_H
#include "batiment.h"
class JointureL:public Batiment
{
public:
    JointureL(const Polyangle & p, float h, float hE,int hm,int sm,float am):Batiment(p,h, hE, hm,sm,am){}
    Mesh generate() const;
};

#endif // JOINTUREL_H
