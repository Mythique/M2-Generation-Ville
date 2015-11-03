#ifndef BATIMENT_H
#define BATIMENT_H
#include "generateur.h"

class Batiment : public Generateur
{
public:
    Batiment();
    virtual Mesh generate()=0;
};

#endif // BATIMENT_H
