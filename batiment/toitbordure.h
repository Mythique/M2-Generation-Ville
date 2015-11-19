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
    ToitBordure(Polyangle p, float h, float hToit, float tailleShrink) : base(p), hauteur(h), hauteurToit(hToit), tailleShrink(tailleShrink){}
    Mesh generate() const;

};

#endif // TOITBORDURE_H
