#include "divisionl.h"
#include "jointurel.h"
#include "toitbusiness.h"
#include "etageresidentiel.h"
#include "meshbuilder.h"
#include "multitoit.h"

DivisionL::DivisionL(const Polyangle & p, float h, float hE,int hm,int sm,float am, Polyangle p1, Polyangle p2, Polyangle p3):Batiment(p,h, hE, hm,sm,am)
{
    poly1 = p1.shrink(p1.plusPetitCote()/10);
    poly2 = p2.shrink(p2.plusPetitCote()/10);
    poly3 = p3.shrink(p3.plusPetitCote()/10);
}

DivisionL::DivisionL(const Polyangle & p, float h, float hE,int hm,int sm,float am)
{

}

Polyangle DivisionL::getPoly1() const
{
    return poly1;
}

void DivisionL::setPoly1(const Polyangle &value)
{
    poly1 = value;
}

Polyangle DivisionL::getPoly2() const
{
    return poly2;
}

void DivisionL::setPoly2(const Polyangle &value)
{
    poly2 = value;
}

Polyangle DivisionL::getPoly3() const
{
    return poly3;
}

void DivisionL::setPoly3(const Polyangle &value)
{
    poly3 = value;
}

Mesh DivisionL::generate() const
{
    MeshBuilder mb;
    QVector<std::pair<Batiment*,int>> bats;

    EtageResidentiel el1(poly1, hauteur, hauteurEtage, hMax, shrinkMax, aireMin);
    EtageResidentiel el2(poly2, hauteur, hauteurEtage, hMax, shrinkMax, aireMin);
    EtageResidentiel el3(poly3, hauteur, hauteurEtage, hMax, shrinkMax, aireMin);

    Mesh etageMesh = mb.generationEtage(&el1);
    etageMesh.merge(mb.generationEtage(&el2));
    etageMesh.merge(mb.generationEtage(&el3));

    QVector<Polyangle> polys;
    polys << poly1 << poly2 << poly3;

    MultiToit dt (base, hauteur+hauteurEtage, hauteurEtage, hMax-1, shrinkMax, aireMin, polys);
    DivisionL dl(base, hauteur+hauteurEtage, hauteurEtage, hMax-1, shrinkMax, aireMin, poly1, poly2, poly3);
    JointureL jl(base, hauteur+hauteurEtage, hauteurEtage, hMax-1, shrinkMax, aireMin, poly1, poly2, poly3);

    bats.append(std::make_pair(&dt, 5));
    if(hMax >1)
    {
        bats.append(std::make_pair(&dl, 20));
        bats.append(std::make_pair(&jl, 20));
    }
    etageMesh.merge(Batiment::getRandomBatiment(bats)->generate());

    return etageMesh;
}
