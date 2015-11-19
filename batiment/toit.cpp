#include "toit.h"
#include <iostream>

Toit::Toit()
{
}

Mesh Toit::generate() const
{
    QList<Vector3D> geom;
    QList<int> topo;
    QList<Vector3D> normales;

    int nbPoints = base.getLesPoints().size();

    // Géométrie
    Vector3D e(0,0,0);
    for (int i = 0; i < nbPoints; i++)
    {
        e += Vector3D(base.getLesPoints()[i], hauteur + hauteurToit);
        geom << Vector3D(base.getLesPoints()[i], hauteur);
    }
    e /= nbPoints;
    geom << e;

    // Topologie
    for (int i = 0; i < nbPoints; i++)
    {
        int p1, p2, p3;
        p1 = nbPoints;
        p2 = i;
        p3 = (i+1)%nbPoints;

        Vector3D n = (geom[p1]-geom[p3])^(geom[p2]-geom[p3]);
        n.normalize();

        normales.push_back(n);

        // indice point, indice texture, indice normale
        topo << p1 << 0 << i
             << p2 << 0 << i
             << p3 << 0 << i;
    }

    return Mesh(geom, topo, normales, "toit");
}
