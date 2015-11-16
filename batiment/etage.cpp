#include "etage.h"
#include <iostream>
#include "mathutils.h"
#include "toit.h"
#include "toitplat.h"

Etage::Etage()
{

}

Mesh Etage::generate()
{
    QList<Vector3D> geom;
    QList<int> topo;
    QList<Vector3D> normales;
    Polyangle baseShrinked = base.shrink(base.perimetre()/100);

    int nbPoints = base.getLesPoints().size();

    // Géométrie
    for (int i = 0; i < nbPoints; i++)
    {
        geom << Vector3D(baseShrinked.getLesPoints()[i], hauteur);
        geom << Vector3D(baseShrinked.getLesPoints()[i], hauteur + hauteurEtage/10);
        geom << Vector3D(base.getLesPoints()[i], hauteur + hauteurEtage/10);
        geom << Vector3D(base.getLesPoints()[i], hauteur + hauteurEtage);
    }

    // Topologie
    int nbBases = 4;
    for (int i = 0; i < nbPoints*nbBases; i++)
    {
        if ((i+1)%nbBases != 0)
        {
            int p1, p2, p3, p4;
            Vector3D n(1,0,0);
            p1 = i;
            p2 = (i + nbBases) % (nbBases*nbPoints);
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

    // Topologie plafond
    for (int i = 1; i < nbPoints-1; i++)
    {
        int p1, p2, p3;
        p1 = nbBases-1;
        p2 = nbBases-1 + i*nbBases;
        p3 = nbBases-1 + (i+1)*nbBases;

        topo << p1 << 0 << i
             << p2 << 0 << i
             << p3 << 0 << i;
    }

    Mesh etageMesh = Mesh(geom, topo, normales, "etage");

    double rand = MathUtils::random(0.0, 1.0);
    if (rand < 0.1)
    {
        double rand2 = MathUtils::random(0.0, 1.0);
        if (rand2 < 0.5)
        {
            //std::cout << "Toit" << std::endl;
            Toit toit = Toit(base, hauteur + hauteurEtage, hauteurEtage / 2);
            etageMesh.merge(toit.generate());
            return etageMesh;
        }
        else
        {
            //std::cout << "Toit Plat" << std::endl;
            ToitPlat toitPlat = ToitPlat(base, hauteur + hauteurEtage, hauteurEtage / 4, base.perimetre()/20);
            etageMesh.merge(toitPlat.generate());
            return etageMesh;
        }
    }
    else
    {
        //std::cout << "Etage" << std::endl;
        double rand2 = MathUtils::random(0.0, 1.0);
        if (rand2 < 0.5)
        {
            Etage etageSup = Etage(base, hauteur + hauteurEtage, hauteurEtage);
            etageMesh.merge(etageSup.generate());
            return etageMesh;
        }
        else
        {
            //std::cout << "plus petit" << std::endl;
            Etage etageSup = Etage(base.shrink(base.perimetre()/50), hauteur + hauteurEtage, hauteurEtage);
            etageMesh.merge(etageSup.generate());
            return etageMesh;
        }
    }
}

