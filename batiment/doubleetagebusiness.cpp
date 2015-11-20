#include "doubleetagebusiness.h"
#include <iostream>
#include "mathutils.h"
#include "toit.h"
#include "toitplat.h"
#include "polyanglehauteur.h"
#include "meshbuilder.h"
#include "etage.h"
#include "etagebusiness.h"

DoubleEtageBusiness::DoubleEtageBusiness(const Polyangle & p, float h, float hE,int hm,int sm,float am):Batiment(p,h, hE, hm,sm,am)
{
    QVector<Vector2D> points = base.getLesPoints();
    std::pair<int, int> indices = base.getHighestPair();
    Vector2D p1(points[indices.first]);
    Vector2D p2(points[(indices.first+1)%points.length()]);
    Vector2D p3(points[indices.second]);
    Vector2D p4(points[(indices.second+1)%points.length()]);

    Vector2D p1Prime = (p1+p2)*0.5;
    Vector2D p2Prime = (p3+p4)*0.5;
    Droite coupe(p1Prime, p2Prime-p1Prime);
    Polyangle r;
    base.split(poly1,r, poly2, coupe,poly1.plusPetitCote()/10);

    poly1 = poly1.shrink(poly1.plusPetitCote()/10);
    poly2 = poly2.shrink(poly2.plusPetitCote()/10);
}

Polyangle DoubleEtageBusiness::getPoly1() const
{
    return poly1;
}

void DoubleEtageBusiness::setPoly1(const Polyangle &value)
{
    poly1 = value;
}

Polyangle DoubleEtageBusiness::getPoly2() const
{
    return poly2;
}

void DoubleEtageBusiness::setPoly2(const Polyangle &value)
{
    poly2 = value;
}

Mesh DoubleEtageBusiness::generate() const
{
    Mesh etageMesh;

    EtageBusiness etageSup1(poly1, hauteur, hauteurEtage, hMax, shrinkMax, aireMin);
    etageMesh.merge(etageSup1.generate());

    EtageBusiness etageSup2(poly2, hauteur, hauteurEtage, hMax, shrinkMax, aireMin);
    etageMesh.merge(etageSup2.generate());
    return etageMesh;
}
