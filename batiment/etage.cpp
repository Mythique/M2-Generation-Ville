#include "etage.h"
#include <iostream>

Etage::Etage()
{

}

Mesh Etage::generate()
{
    QList<Vector3D> geom;
    QList<int> topo;
    QList<Vector3D> normales;

    int nbPoints = base.getLesPoints().size();

    // Géométrie
    for (int i = 0; i < nbPoints; i++)
    {
        geom << Vector3D(base.getLesPoints()[i], hauteur);
    }

    for (int i = 0; i < nbPoints; i++)
    {
        geom << Vector3D(base.getLesPoints()[i], hauteur + hauteurEtage);
    }

    // Test de l'orientation des points pour les normales
    /*Vector3D a = base.getLesPoints()[0];
    Vector3D b = base.getLesPoints()[1];
    Vector3D c = base.getLesPoints()[2];
    Vector3D orientation = (c-b)^(a-b);*/

    // Topologie
    for (int i = 0; i < nbPoints; i++)
    {
        int p1, p2, p3, p4;
        Vector3D n;
        p1 = i;
        p2 = (i+1)%nbPoints;
        p3 = i+nbPoints;

        n = (geom[p3]-geom[p2])^(geom[p1]-geom[p2]);
        /*if (orientation.y() > 0)
        {

        }
        else
        {
            p1 = i;
            p2 = i+nbPoints;
            p3 = (i+1)%nbPoints;

            n = (geom[p1]-geom[p2])^(geom[p3]-geom[p2]);
        }*/

        p4 = (i+1)%nbPoints+nbPoints;

        n.normalize();
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

    return Mesh(geom, topo, normales, "etage");
}

