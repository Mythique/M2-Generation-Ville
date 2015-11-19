#ifndef ETAGERESIDENTIEL_H
#define ETAGERESIDENTIEL_H
#include "batiment.h"

class EtageResidentiel:public Batiment
{
public:
    EtageResidentiel(const Polyangle & p, float h, float hE,int hm,int sm,float am):Batiment(p,h, hE, hm,sm,am){}
    Mesh generate() const;
};


#endif // ETAGERESIDENTIEL_H
