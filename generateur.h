#ifndef GENERATEUR_H
#define GENERATEUR_H
#include "mesh.h";

class Generateur
{
public:
    Generateur();
    virtual Mesh generate()=0;
};

#endif // GENERATEUR_H
