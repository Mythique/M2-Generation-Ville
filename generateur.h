#ifndef GENERATEUR_H
#define GENERATEUR_H
#include "mesh.h"

/**
 * @brief The Generateur class, base of every class that generates a Mesh.
 */
class Generateur
{
public:
    Generateur();
    virtual Mesh generate() const =0;
};

#endif // GENERATEUR_H
