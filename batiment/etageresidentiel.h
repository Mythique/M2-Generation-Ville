#ifndef ETAGERESIDENTIEL_H
#define ETAGERESIDENTIEL_H
#include "batiment.h"

class EtageResidentiel:public Batiment
{
public:
    EtageResidentiel(int hm,int sm,float am):Batiment(hm,sm,am){}
    Mesh generate() const;
};


#endif // ETAGERESIDENTIEL_H
