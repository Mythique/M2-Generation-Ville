#ifndef TOITPLAT_H
#define TOITPLAT_H
#include "batiment.h"
#include "vector3d.h"
#include "polyangle.h"
#include "mesh.h"

class ToitPlat
{
private:
    Polyangle base;
    float hauteur, hauteurToit, tailleShrink;
public:
    ToitPlat();
    ToitPlat(Polyangle p, float h, float hToit, float tailleShrink) : base(p), hauteur(h), hauteurToit(hToit), tailleShrink(tailleShrink){}
    Mesh generate() const;
};

#endif // TOITPLAT_H
