#include "parcelle.h"
#include "../batiment/rezdechaussee.h"


void Parcelle::generate(Mesh &m)
{
    RezDeChaussee rdc(poly,0,3);
    Mesh bat=rdc.generate();
    m.merge(bat);
}

