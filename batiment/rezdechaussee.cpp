#include "rezdechaussee.h"
#include "etage.h"

RezDeChaussee::RezDeChaussee()
{

}


Mesh RezDeChaussee::generate()
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
        geom << Vector3D(base.getLesPoints()[i], hauteur + hauteurRDC);
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

    // Topologie plafond
    for (int i = 1; i < nbPoints - 1; i++)
    {
        int p1, p2, p3;
        p1 = nbPoints;
        p2 = nbPoints + i;
        p3 = nbPoints + (i+1)%nbPoints;

        // indice point, indice texture, indice normale
        // Premier triangle
        topo << p1 << 0 << 1
             << p2 << 0 << 1
             << p3 << 0 << 1;
    }

    Mesh rdcMesh = Mesh(geom, topo, normales, "RDC");
    Etage etage = Etage(base, hauteur + hauteurRDC, hauteurRDC);
    rdcMesh.merge(etage.generate());
    return rdcMesh;
}
