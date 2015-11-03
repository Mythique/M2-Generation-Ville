#include "toit.h"
#include <iostream>

Toit::Toit()
{
}

Mesh Toit::generate()
{
    Vector3D e = (a+b+c+d)/4;
    e.setY(e.y()+hauteur);
    QList<Vector3D> geom;
    geom << a << b << c << d << e;

    QList<int> topo;
    QList<Vector3D> normales;

    // Test de l'orientation des points pour les normales
    Vector3D orientation = (c-b)^(a-b);

    for (int i = 0; i < 4; i++)
    {
        int p1, p2, p3;
        if (orientation.y() < 0)
        {
            p1 = 4;
            p2 = (i+1)%4;
            p3 = i;
        }
        else
        {
            p1 = 4;
            p2 = i;
            p3 = (i+1)%4;
        }

        Vector3D n = (geom[p2]-geom[p3])^(geom[p1]-geom[p3]);
        n.normalize();

        normales.push_back(n);

        // indice point, indice texture, indice normale
        topo << p1 << 0 << i
             << p2 << 0 << i
             << p3 << 0 << i;
    }

    return Mesh(geom, topo, normales, "toit");
}
