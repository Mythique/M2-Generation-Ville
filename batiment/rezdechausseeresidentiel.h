#ifndef REZDECHAUSSERESIDENTIEL_H
#define REZDECHAUSSERESIDENTIEL_H
#include "batiment.h"

class RezDeChausseeResidentiel:public Batiment
{
public:
    RezDeChausseeResidentiel(const Polyangle & p, float h, float hE,int hm,int sm,float am):Batiment(p,h, hE, hm,sm,am){}
    Mesh generate() const;
};

#endif // REZDECHAUSSERESIDENTIEL_H
