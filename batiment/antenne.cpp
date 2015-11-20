#include "antenne.h"
#include "meshbuilder.h"
#include "polyanglehauteur.h"

Mesh Antenne::
generate() const
{
    MeshBuilder mb;
    Vector2D centre2D = base.getCentre();
    Vector3D centre(centre2D.x(), centre2D.y(), hauteur);
    Mesh antenneMesh = mb.generationCone(centre, hauteurEtage, 5, base.plusPetitCote()/5);
    return antenneMesh;
}
