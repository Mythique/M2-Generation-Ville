#include "jointure.h"
#include "doubletoit.h"
#include "division.h"

Jointure::Jointure(const Polyangle & p, float h, float hE,int hm,int sm,float am, const Polyangle & p1, const Polyangle & p2):Batiment(p,h, hE, hm,sm,am), poly1(p1), poly2(p2)
{

}

Mesh generate() const
{




    MeshBuilder mb;
    Mesh etageMesh = mb.generationEtage(poly1);
    etageMesh.merge(mb.generationEtage(poly2));

    QVector<std::pair<Batiment*,int>> bats;

    DoubleToit dt(base, hauteur, hauteurEtage, hMax-1, shrinkMax, aireMin, poly1, poly2);
    Division d(base, hauteur, hauteurEtage, hMax-1, shrinkMax, aireMin, poly1, poly2);

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
