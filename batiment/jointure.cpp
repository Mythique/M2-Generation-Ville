#include "jointure.h"
#include "doubletoit.h"
#include "division.h"
#include "../meshbuilder.h"
#include "etageresidentiel.h"

Jointure::Jointure(const Polyangle & p, float h, float hE,int hm,int sm,float am, const Polyangle & p1, const Polyangle & p2):Batiment(p,h, hE, hm,sm,am), poly1(p1), poly2(p2)
{

}

Mesh Jointure::generate() const
{
    Vector2D centre1 = poly1.getCentre();
    Vector2D centre2 = poly2.getCentre();

    Vector2D c1c2 = (centre2-centre1);
    c1c2.normalize();

    Vector2D ortho(-(c1c2.y()), c1c2.x());

    Vector2D p1(centre1 + hauteurEtage/2*ortho);
    Vector2D p2(centre1 - hauteurEtage/2*ortho);
    Vector2D p3(centre2 - hauteurEtage/2*ortho);
    Vector2D p4(centre2 + hauteurEtage/2*ortho);

    QVector<Vector2D> points;
    points << p1 <<p2<<p3<<p4;
    Polyangle poly(points);

    QVector<PolyangleHauteur> polyh;
    QVector<PolyangleHauteur> polyh2;
    polyh << PolyangleHauteur(poly, hauteur/2) << PolyangleHauteur(poly, hauteur+hauteurEtage);
    polyh2 << PolyangleHauteur(poly, hauteur/2) << PolyangleHauteur(poly, hauteur);



    MeshBuilder mb;
    Mesh partie1 = mb.generationPolyanglesRelies(polyh);
    Mesh partie2 = mb.generationPolyanglesRelies(polyh2);


    EtageResidentiel er1(poly1, hauteur, hauteurEtage, hMax, shrinkMax, aireMin);
    EtageResidentiel er2(poly2, hauteur, hauteurEtage, hMax, shrinkMax, aireMin);
    Mesh etageMesh = mb.generationEtage(&er1);
    etageMesh.merge(mb.generationEtage(&er2));
    etageMesh.merge(partie1);
    etageMesh.merge(partie2);

    QVector<std::pair<Batiment*,int>> bats;

    DoubleToit dt(base, hauteur+hauteurEtage, hauteurEtage, hMax-1, shrinkMax, aireMin, poly1, poly2);
    Division d(base, hauteur+hauteurEtage, hauteurEtage, hMax-1, shrinkMax, aireMin, poly1, poly2);

    bats.append(std::make_pair(&dt, 10));

    if(hMax > 1)
    {
        bats.append(std::make_pair(&d, 20));
    }

    etageMesh.merge(Batiment::getRandomBatiment(bats)->generate());
    return etageMesh;
}


Polyangle Jointure::getPoly1() const
{
    return poly1;
}

void Jointure::setPoly1(const Polyangle &value)
{
    poly1 = value;
}

Polyangle Jointure::getPoly2() const
{
    return poly2;
}

void Jointure::setPoly2(const Polyangle &value)
{
    poly2 = value;
}
