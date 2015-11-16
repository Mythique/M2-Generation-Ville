#include "quartier.h"


Quartier::Quartier(Polyangle polya, double tailleTrottoir, double tailleBatiment) : poly(polya)
{
    Polyangle terrainEtape1;
}
Quartier::Quartier(const Polyangle &p, TypeQuartier tq) : poly(p), type(tq)
{

}


void Quartier::generate(QList<Mesh> &meshes)
{

}

const Polyangle Quartier::getPoly()
{
    return poly;
}

