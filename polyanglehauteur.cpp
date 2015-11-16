#include "polyanglehauteur.h"

PolyangleHauteur::PolyangleHauteur()
{

}

float PolyangleHauteur::getHauteur() const
{
    return hauteur;
}

void PolyangleHauteur::setHauteur(float value)
{
    hauteur = value;
}

Polyangle PolyangleHauteur::getPolyangle() const
{
    return polyangle;
}

void PolyangleHauteur::setPolyangle(const Polyangle &value)
{
    polyangle = value;
}
