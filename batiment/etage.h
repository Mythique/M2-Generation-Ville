#ifndef ETAGE_H
#define ETAGE_H
#include "batiment.h"
#include "vector3d.h"
#include "mesh.h"
#include "polyangle.h"

class Etage : public Batiment
{
private:
    Polyangle base;
    float hauteur, hauteurEtage;
public:
    Etage();
    Etage(Polyangle p, float h, float hE) : base(p), hauteur(h), hauteurEtage(hE) {}
    Mesh generate() const;
};

#endif // ETAGE_H
