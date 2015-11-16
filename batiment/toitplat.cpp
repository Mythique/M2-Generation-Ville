#include "toitplat.h"

ToitPlat::ToitPlat()
{

}

Mesh ToitPlat::generate()
{
    QList<Vector3D> geom;
    QList<int> topo;
    QList<Vector3D> normales;
    Polyangle baseShrinked = base.shrink(tailleShrink);

    int nbPoints = base.getLesPoints().size();

    // Géométrie
    for (int i = 0; i < nbPoints; i++)
    {
        geom << Vector3D(base.getLesPoints()[i], hauteur);
        geom << Vector3D(baseShrinked.getLesPoints()[i], hauteur + hauteurToit);
    }

    // Topologie
    for (int i = 0; i < nbPoints; i++)
    {
        int p1, p2, p3, p4;
        Vector3D n(1,0,0);
        p1 = 2*i;
        p2 = 2*(i+1) % (nbPoints * 2);
        p3 = 2*i + 1;
        p4 = p2 + 1;

        normales.push_back(n);
        normales.push_back(n);

        // indice point, indice texture, indice normale
        // Premier triangle
        topo << p1 << 0 << i
             << p2 << 0 << i
             << p3 << 0 << i;
        // Second triangle
        topo << p3 << 0 << i
             << p2 << 0 << i
             << p4 << 0 << i;
    }

    // Topologie plafond
    for (int i = 1; i < nbPoints-1; i++)
    {
        int p1, p2, p3;
        p1 = 1;
        p2 = p1 + 2*i;
        p3 = p1 + 2*(i+1);

        topo << p1 << 0 << i
             << p2 << 0 << i
             << p3 << 0 << i;
    }

    return Mesh(geom, topo, normales, "toitPlat");
}
