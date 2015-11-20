#ifndef TOITPLAT_H
#define TOITPLAT_H
#include "batiment.h"
#include "vector3d.h"
#include "polyangle.h"
#include "mesh.h"

class ToitPlat : public Batiment
{
private:
    Polyangle base;
    float hauteur, hauteurToit;
public:
    ToitPlat();
    ToitPlat(Polyangle p, float h, float hToit) : base(p), hauteur(h), hauteurToit(hToit){}
    Mesh generate() const;
};

#endif // TOITPLAT_H
