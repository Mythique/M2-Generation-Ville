#ifndef POLYANGLEHAUTEUR_H
#define POLYANGLEHAUTEUR_H
#include "polyangle.h"

class PolyangleHauteur
{
private:
    Polyangle polyangle;
    float hauteur;
public:
    PolyangleHauteur();
    PolyangleHauteur(Polyangle p, float h) : polyangle(p), hauteur(h){}
    Polyangle getPolyangle() const;
    void setPolyangle(const Polyangle &value);
    float getHauteur() const;
    void setHauteur(float value);
};

#endif // POLYANGLEHAUTEUR_H
