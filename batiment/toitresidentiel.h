#ifndef TOITRESIDENTIEL_H
#define TOITRESIDENTIEL_H
#include "batiment.h"

class ToitResidentiel:public Batiment
{
public:
    ToitResidentiel(int hm,int sm,float am):Batiment(hm,sm,am){}
    Mesh generate() const;
};

#endif // TOITRESIDENTIEL_H
