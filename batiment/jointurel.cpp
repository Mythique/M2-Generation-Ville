#include "jointurel.h"
#include "etageresidentiel.h"
#include "multitoit.h"
#include "divisionl.h"
#include "../meshbuilder.h"

JointureL::JointureL(const Polyangle & p, float h, float hE, int hm, int sm, float am, const Polyangle &p1, const Polyangle &p2, const Polyangle &p3):Batiment(p,h, hE, hm,sm,am),poly1(p1),poly2(p2),poly3(p3){}

Mesh JointureL::generate() const
{
    MeshBuilder mb;

    Vector2D centre1 = poly1.getCentre();
    Vector2D centre2 = poly2.getCentre();
    Vector2D centre3 = poly3.getCentre();

    Vector2D c1c2 = (centre2-centre1);
    c1c2.normalize();

    Vector2D c2c3 = (centre3-centre2);
    c2c3.normalize();

    Vector2D ortho(-(c1c2.y()), c1c2.x());
    Vector2D ortho2(-(c2c3.y()), c2c3.x());

    Vector2D p1(centre1 + hauteurEtage/2*ortho);
    Vector2D p2(centre1 - hauteurEtage/2*ortho);
    Vector2D p3(centre2 - hauteurEtage/2*ortho);
    Vector2D p4(centre2 + hauteurEtage/2*ortho);

    QVector<Vector2D> points;
    points << p1 <<p2<<p3<<p4;
    Polyangle poly(points);

    QVector<PolyangleHauteur> polyh;
    QVector<PolyangleHauteur> polyh2;
    polyh << PolyangleHauteur(poly, hauteur+hauteurEtage/8) << PolyangleHauteur(poly, hauteur+7.0/8.0*hauteurEtage);
    polyh2 << PolyangleHauteur(poly, hauteur+hauteurEtage/8);

    Mesh partie1 = mb.generationPolyanglesRelies(polyh);
    Mesh partie2 = mb.generationPolyanglesRelies(polyh2);


    Vector2D p5(centre2 + hauteurEtage/2*ortho2);
    Vector2D p6(centre2 - hauteurEtage/2*ortho2);
    Vector2D p7(centre3 - hauteurEtage/2*ortho2);
    Vector2D p8(centre3 + hauteurEtage/2*ortho2);

    QVector<Vector2D> points2;
    points2 << p5 <<p6<<p7<<p8;
    Polyangle polyy(points2);

    QVector<PolyangleHauteur> polyh3;
    QVector<PolyangleHauteur> polyh4;
    polyh3 << PolyangleHauteur(polyy, hauteur+hauteurEtage/8) << PolyangleHauteur(polyy, hauteur+7.0/8.0*hauteurEtage);
    polyh4 << PolyangleHauteur(polyy, hauteur+hauteurEtage/8);

    Mesh partie3 = mb.generationPolyanglesRelies(polyh3);
    Mesh partie4 = mb.generationPolyanglesRelies(polyh4);

    QVector<std::pair<Batiment*,int>> bats;

    EtageResidentiel el1(poly1, hauteur, hauteurEtage, hMax, shrinkMax, aireMin);
    EtageResidentiel el2(poly2, hauteur, hauteurEtage, hMax, shrinkMax, aireMin);
    EtageResidentiel el3(poly3, hauteur, hauteurEtage, hMax, shrinkMax, aireMin);

    Mesh etageMesh = mb.generationEtage(&el1);
    etageMesh.merge(mb.generationEtage(&el2));
    etageMesh.merge(mb.generationEtage(&el3));
    etageMesh.merge(partie1);
    etageMesh.merge(partie2);
    etageMesh.merge(partie3);
    etageMesh.merge(partie4);

    QVector<Polyangle> polys;
    polys << poly1 << poly2 << poly3;

    MultiToit dt (base, hauteur+hauteurEtage, hauteurEtage, hMax-1, shrinkMax, aireMin, polys);
    DivisionL dl(base, hauteur+hauteurEtage, hauteurEtage, hMax-1, shrinkMax, aireMin, poly1, poly2, poly3,false);

    bats.append(std::make_pair(&dt, 5));
    if(hMax >1)
    {
        bats.append(std::make_pair(&dl, 20));
    }
    etageMesh.merge(Batiment::getRandomBatiment(bats)->generate());

    return etageMesh;
}

Polyangle JointureL::getPoly2() const
{
    return poly2;
}

void JointureL::setPoly2(const Polyangle &value)
{
    poly2 = value;
}

Polyangle JointureL::getPoly3() const
{
    return poly3;
}

void JointureL::setPoly3(const Polyangle &value)
{
    poly3 = value;
}

Polyangle JointureL::getPoly1() const
{
    return poly1;
}

void JointureL::setPoly1(const Polyangle &value)
{
    poly1 = value;
}
