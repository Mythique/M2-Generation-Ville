#ifndef TOITBORDURE_H
#define TOITBORDURE_H
#include "batiment.h"
#include "vector3d.h"
#include "polyangle.h"
#include "mesh.h"

class ToitBordure
{
private:
    Polyangle base;
    float hauteur, hauteurToit;
public:
    ToitBordure();
    ToitBordure(Polyangle p, float h, float hToit) : base(p), hauteur(h), hauteurToit(hToit){}
    Mesh generate();
};

#endif // TOITBORDURE_H
