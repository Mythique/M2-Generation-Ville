#ifndef REZDECHAUSSEE_H
#define REZDECHAUSSEE_H
#include "batiment.h"
#include "vector3d.h"
#include "mesh.h"
#include "polyangle.h"

class RezDeChaussee : public Batiment
{
private:
    Polyangle base;
    float hauteur, hauteurRDC;
public:
    RezDeChaussee();
    RezDeChaussee(Polyangle p, float h, float hRDC) : base(p), hauteur(h), hauteurRDC(hRDC) {}
    Mesh generate();
};

#endif // REZDECHAUSSEE_H