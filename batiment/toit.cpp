#include "toit.h"
#include <iostream>

Toit::Toit()
{
}

Mesh Toit::generate()
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

    // Test de l'orientation des points pour les normales
    Vector3D a = base.getLesPoints()[0];
    Vector3D b = base.getLesPoints()[1];
    Vector3D c = base.getLesPoints()[2];
    Vector3D orientation = (c-b)^(a-b);

    // Topologie
    for (int i = 0; i < nbPoints; i++)
    {
        int p1, p2, p3;
        Vector3D n;
        if (orientation.y() > 0)
        {
            p1 = nbPoints;
            p2 = i;
            p3 = (i+1)%nbPoints;

            n = (geom[p2]-geom[p3])^(geom[p1]-geom[p3]);
        }
        else
        {
            p1 = nbPoints;
            p2 = (i+1)%nbPoints;
            p3 = i;

            n = (geom[p1]-geom[p3])^(geom[p2]-geom[p3]);
        }


        n.normalize();

        normales.push_back(n);

        // indice point, indice texture, indice normale
        topo << p1 << 0 << i
             << p2 << 0 << i
             << p3 << 0 << i;
    }

    return Mesh(geom, topo, normales, "toit");
}
