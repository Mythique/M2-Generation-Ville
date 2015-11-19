#include "toitresidentiel.h"
#include "toit.h"
#include "cheminee.h"

Mesh ToitResidentiel::generate() const
{
    Toit t1(base,hauteur,hauteurEtage);
    Cheminee cheminee(base, hauteur, hauteurEtage / 2, hMax, shrinkMax, aireMin);
    Mesh toitMesh = t1.generate();
    toitMesh.merge(cheminee.generate());
    return toitMesh;
}
