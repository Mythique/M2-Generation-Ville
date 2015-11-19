#ifndef GENERATEUR_H
#define GENERATEUR_H
#include "mesh.h"

class Generateur
{
public:
    Generateur();
    virtual Mesh generate() const =0;
};

#endif // GENERATEUR_H
