#include "toitbordure.h"

ToitBordure::ToitBordure()
{

}

Mesh ToitBordure::generate() const
{
    QList<Vector3D> geom;
    QList<int> topo;
    QList<Vector3D> normales;
    Polyangle baseShrinked = base.shrink(base.perimetre()/100);

    return Mesh();
}
