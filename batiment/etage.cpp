#include "etage.h"
#include <iostream>
#include "mathutils.h"
#include "toit.h"

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

    // Topologie
    for (int i = 0; i < nbPoints; i++)
    {
        int p1, p2, p3, p4;
        Vector3D n;
        p1 = i;
        p2 = (i+1)%nbPoints;
        p3 = i+nbPoints;

        n = (geom[p3]-geom[p2])^(geom[p1]-geom[p2]);

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

    Mesh etageMesh = Mesh(geom, topo, normales, "etage");

    double rand = MathUtils::random(0.0, 1.0);
    std::cout << rand << std::endl;
    if (rand < 0.5)
    {
        std::cout << "Toit !" << std::endl;
        Toit toit = Toit(base, hauteur + hauteurEtage, hauteurEtage / 2);
        etageMesh.merge(toit.generate());

        return etageMesh;
    }
    else
    {
        std::cout << "Etage !" << std::endl;
        Etage etageSup = Etage(base, hauteur + hauteurEtage, hauteurEtage);
        etageMesh.merge(etageSup.generate());
        return etageMesh;
    }
}

