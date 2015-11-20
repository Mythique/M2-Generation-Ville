#ifndef TOITANTENNE_H
#define TOITANTENNE_H
#include "batiment.h"
#include "vector3d.h"
#include "polyangle.h"
#include "mesh.h"

class ToitAntenne : public Batiment
{
private:
    Polyangle base;
    float hauteur;
    float hauteurToit;
    float hauteurAntenne;
public:
    ToitAntenne();
    ToitAntenne(Polyangle p, float h, float hToit, float hAntenne) : base(p), hauteur(h), hauteurToit(hToit), hauteurAntenne(hAntenne){}
    Mesh generate() const;
};

#endif // TOITANTENNE_H
