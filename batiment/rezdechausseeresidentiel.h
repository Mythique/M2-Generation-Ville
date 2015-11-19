#ifndef REZDECHAUSSERESIDENTIEL_H
#define REZDECHAUSSERESIDENTIEL_H
#include "batiment.h"

class RezDeChausseeResidentiel:public Batiment
{
public:
    RezDeChausseeResidentiel(int hm,int sm,float am):Batiment(hm,sm,am){}
    Mesh generate() const;
};

#endif // REZDECHAUSSERESIDENTIEL_H
