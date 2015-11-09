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
    Polyangle baseShrinked = base.shrink(hauteurEtage/10);

    int nbPoints = base.getLesPoints().size();
    std::cout << nbPoints << std::endl;

    // Géométrie
    for (int i = 0; i < nbPoints; i++)
    {
        geom << Vector3D(baseShrinked.getLesPoints()[i], hauteur);
        //geom << Vector3D(baseShrinked.getLesPoints()[i], hauteur + hauteurEtage/10);
        geom << Vector3D(base.getLesPoints()[i], hauteur + hauteurEtage/10);
        geom << Vector3D(base.getLesPoints()[i], hauteur + hauteurEtage);
    }

    // Topologie
    for (int i = 0; i < 1; i++)
    {
        if ((i+1)%3)
        {
            int p1, p2, p3, p4;
            Vector3D n(1,0,0);
            p1 = i;
            p2 = (i + 3) % (3*nbPoints);
            p3 = i + 1;
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
    }

    return Mesh(geom, topo, normales, "etage");

    /*for (int i = 0; i < nbPoints; i++)
    {
        geom << Vector3D(base.getLesPoints()[i], hauteur + hauteurEtage/10);
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
        p4 = (i+1)%nbPoints+nbPoints;

        n = (geom[p3]-geom[p2])^(geom[p1]-geom[p2]);
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


    Mesh etageMesh = Mesh(geom, topo, normales, "etage");

    double rand = MathUtils::random(0.0, 1.0);
    if (rand < 0.2)
    {
        Toit toit = Toit(base, hauteur + hauteurEtage, hauteurEtage / 2);
        etageMesh.merge(toit.generate());

        return etageMesh;
    }
    else
    {
        Etage etageSup = Etage(base, hauteur + hauteurEtage, hauteurEtage);
        etageMesh.merge(etageSup.generate());
        return etageMesh;
    }*/
}

