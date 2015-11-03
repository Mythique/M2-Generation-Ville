#ifndef PARCELLE_H
#define PARCELLE_H
#include "generateur.h"

class Parcelle : public Generateur
{
public:
    Parcelle();
    virtual Mesh generate()=0;
};

#endif // PARCELLE_H
