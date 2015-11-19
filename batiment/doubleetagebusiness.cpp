#include "doubleetagebusiness.h"
#include <iostream>
#include "mathutils.h"
#include "toit.h"
#include "toitplat.h"
#include "polyanglehauteur.h"
#include "meshbuilder.h"
#include "etage.h"


Mesh DoubleEtageBusiness::generate() const
{
    Mesh etageMesh;
    QVector<Vector2D> points = base.getLesPoints();
    std::pair<int, int> indices = base.getHighestPair();
    Vector2D p1(points[indices.first]);
    Vector2D p2(points[(indices.first+1)%points.length()]);
    Vector2D p3(points[indices.second]);
    Vector2D p4(points[(indices.second+1)%points.length()]);

    Vector2D p1Prime = (p1+p2)*0.5;
    Vector2D p2Prime = (p3+p4)*0.5;
    Droite coupe(p1Prime, p2Prime-p1Prime);

    Polyangle split1;
    Polyangle split2;
    base.split(split1, split2, coupe);

    split1 = split1.shrink(split1.plusPetitCote()/10);
    split2 = split2.shrink(split2.plusPetitCote()/10);

    Etage etageSup1 = Etage(split1, hauteur, hauteurEtage);
    etageMesh.merge(etageSup1.generate());

    Etage etageSup2 = Etage(split2, hauteur, hauteurEtage);
    etageMesh.merge(etageSup2.generate());
    return etageMesh;
}
