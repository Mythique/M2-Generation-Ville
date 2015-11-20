#include "toit.h"
#include <iostream>
#include "cheminee.h"
#include "meshbuilder.h"
#include "polyanglehauteur.h"

Toit::Toit()
{
}

Mesh Toit::generate() const
{
    MeshBuilder mb;
    Mesh toitMesh = mb.generationCone(PolyangleHauteur(base, hauteur), hauteurToit);
    Cheminee cheminee(base, hauteur, hauteurToit / 2, 1, 1, 1);
    toitMesh.merge(cheminee.generate());
    return toitMesh;
}
