#include "division.h"
#include <iostream>
#include "mathutils.h"
#include "toit.h"
#include "toitplat.h"
#include "polyanglehauteur.h"
#include "meshbuilder.h"
#include "multitoit.h"
#include "etageresidentiel.h"
#include "jointure.h"
#include "../mathutils.h"


Division::Division(const Polyangle & p, float h, float hE,int hm,int sm,float am):Batiment(p,h, hE, hm,sm,am)
{
    QVector<Vector2D> points = base.getLesPoints();
    std::pair<int, int> indices = base.getHighestPair();
    Vector2D p1(points[indices.first]);
    Vector2D p2(points[(indices.first+1)%points.length()]);
    Vector2D p3(points[indices.second]);
    Vector2D p4(points[(indices.second+1)%points.length()]);

    Vector2D p1Prime = (p1+p2)*MathUtils::random(0.4,0.6);
    Vector2D p2Prime = (p3+p4)*MathUtils::random(0.4,0.6);
    Droite coupe(p1Prime, p2Prime-p1Prime);
    base.split(poly1, poly2, coupe);

    poly1 = poly1.shrink(poly1.plusPetitCote()/10);
    poly2 = poly2.shrink(poly2.plusPetitCote()/10);
}


Polyangle Division::getPoly1() const
{
    return poly1;
}

void Division::setPoly1(const Polyangle &value)
{
    poly1 = value;
}

Polyangle Division::getPoly2() const
{
    return poly2;
}

void Division::setPoly2(const Polyangle &value)
{
    poly2 = value;
}

Mesh Division::generate() const
{
    MeshBuilder mb;
    EtageResidentiel er1(poly1, hauteur, hauteurEtage, hMax, shrinkMax, aireMin);
    EtageResidentiel er2(poly2, hauteur, hauteurEtage, hMax, shrinkMax, aireMin);
    Mesh etageMesh = mb.generationEtage(&er1);
    etageMesh.merge(mb.generationEtage(&er2));

    QVector<std::pair<Batiment*,int>> bats;
    QVector<Polyangle> polys;
    polys << poly1 << poly2;

    MultiToit dt(base, hauteur+hauteurEtage, hauteurEtage, hMax-1, shrinkMax, aireMin, polys);

    Division d(base, hauteur+hauteurEtage, hauteurEtage, hMax-1, shrinkMax, aireMin, poly1, poly2);
    Jointure j(base, hauteur+hauteurEtage, hauteurEtage, hMax-1, shrinkMax, aireMin, poly1, poly2);

    bats.append(std::make_pair(&dt, 10));

    if(hMax > 1)
    {
        bats.append(std::make_pair(&d, 20));
        bats.append(std::make_pair(&j, 10));
    }


    etageMesh.merge(Batiment::getRandomBatiment(bats)->generate());
    return etageMesh;
}
