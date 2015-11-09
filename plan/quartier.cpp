#include "quartier.h"

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

