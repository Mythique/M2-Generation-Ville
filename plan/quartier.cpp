#include "quartier.h"
#include "../meshbuilder.h"
#include "../polyanglehauteur.h"


Quartier::Quartier(Polyangle polya, double tailleTrottoir, double tailleBatiment) : poly(polya)
{
    QVector<Polyangle> restes;
    Polyangle exterieur = polya.shrink(tailleTrottoir);
    Polyangle interieur = polya.shrink(tailleTrottoir+tailleBatiment);
    int length = exterieur.getLesPoints().size();

    for(int cpt = 0; cpt < length; cpt++)
    {
        Vector2D a = exterieur.getLesPoints().at((cpt-1+length)%length);
        Vector2D b = exterieur.getLesPoints().at((cpt));
        Vector2D c = exterieur.getLesPoints().at((cpt+1)%length);
        Vector2D bPrime = interieur.getLesPoints()[cpt];
        Vector2D cPrime = interieur.getLesPoints()[(cpt+1)%length];


        Vector2D ba = a-b;
        Vector2D bc = c-b;
        Vector2D bbPrime = bPrime -b;
        Vector2D cb = b-c;
        Vector2D ccPrime = cPrime -c;

        ba.normalize();
        bc.normalize();
        cb.normalize();

        float scalBA = ba*bbPrime;
        float scalBC = bc*bbPrime;
        float scalCB = cb*ccPrime;

        Vector2D p1 = b+(scalBA * ba);
        Vector2D p2 = b+(scalBC * bc);
        Vector2D p3 = c+(scalCB * cb);

        QVector<Vector2D> poly;
        QVector<Vector2D> polyReste;
        poly<<b<< p2<< bPrime<< p1;
        polyReste<<p2<<p3<<cPrime<<bPrime;

        parcelles.append(Parcelle(Polyangle(poly), Parcelle::HABITATION));
        parcelles.append(Parcelle(Polyangle(polyReste), Parcelle::HABITATION));

    }
    //parcelles.append(Parcelle(interieur, Parcelle::JARDIN));


}


Quartier::Quartier(const Polyangle &p, TypeQuartier tq) : poly(p), type(tq)
{

}


void Quartier::generate(Mesh &mesh)
{
    for(int i = 0; i < parcelles.length(); i++)
    {
        parcelles[i].generate(mesh);
    }

    MeshBuilder mb;
    PolyangleHauteur ph1(poly,-0.1);
    PolyangleHauteur ph2(poly,0);
    QVector<PolyangleHauteur> vect;
    vect<<ph1<<ph2;
    mesh.merge(mb.generationPolyanglesRelies(vect));
}

const Polyangle Quartier::getPoly()
{
    return poly;
}

