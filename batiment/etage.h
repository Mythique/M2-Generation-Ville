#ifndef ETAGE_H
#define ETAGE_H
#include "batiment.h"
#include "vector3d.h"
#include "mesh.h"

class Etage : public Batiment
{
private:
    Vector3D a, b, c, d;
    float hauteur;
public:
    Etage();
    Etage(Vector3D a, Vector3D b, Vector3D c, Vector3D d, float h) : a(a), b(b), c(c), d(d), hauteur(h){}
    Mesh generate();
};

#endif // ETAGE_H
