#include "toitbusiness.h"
#include "toit.h"
#include "antenne.h"

Mesh ToitBusiness::generate() const
{
    Toit t1(base,hauteur,hauteurEtage);
    //Antenne antenne(base, hauteur, hauteurEtage / 2, hMax, shrinkMax, aireMin);
    Mesh toitMesh = t1.generate();
    //toitMesh.merge(antenne.generate());
    return toitMesh;
}
