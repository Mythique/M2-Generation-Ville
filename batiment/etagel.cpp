#include "etagel.h"
#include "toitbusiness.h"
#include "droite.h"
#include "meshbuilder.h"
#include "etageresidentiel.h"

EtageL::EtageL(const Polyangle & p, float h, float hE,int hm,int sm,float am):Batiment(p,h, hE, hm,sm,am)
{
    base = base.shrink(base.plusPetitCote()/10);
    QVector<Vector2D> points = base.getLesPoints();

    if(points.size() > 3)
    {
        Vector2D p1 = (points[2]+points[3])*0.5;
        Vector2D p2 = (points[0]+points[points.size()-1])*0.5;

        Droite d1(p1, points[2]-points[1]);
        Droite d2(p2, points[1]-points[0]);

        Vector2D inter;
        QVector<Vector2D> lesPoints1;
        QVector<Vector2D> lesPoints2;
        QVector<Vector2D> lesPoints3;
        if(d1.getIntersection(d2, inter))
        {
            lesPoints1 << points[0] << (points[0]+points[1])*0.5 << inter << p2;
            lesPoints2 << (points[0]+points[1])*0.5 << points[1] << (points[1]+points[2])*0.5 << inter;
            lesPoints3 << (points[1]+points[2])*0.5 << points[2] << p1 << inter;
        }
        poly1 = Polyangle(lesPoints1);
        poly2 = Polyangle(lesPoints2);
        poly3 = Polyangle(lesPoints3);
        //std::cout << base.getLesPoints() << std::endl;
    }


}

Mesh EtageL::generate() const
{
   /* QVector<PolyangleHauteur> polyh;
    QVector<PolyangleHauteur> polyh2;
    QVector<PolyangleHauteur> polyh3;
    polyh << PolyangleHauteur(poly1, hauteur)
          << PolyangleHauteur(poly1, hauteur + hauteurEtage);
    polyh2 << PolyangleHauteur(poly2, hauteur)
           << PolyangleHauteur(poly2, hauteur + hauteurEtage);
    polyh3 << PolyangleHauteur(poly3, hauteur)
           << PolyangleHauteur(poly3, hauteur + hauteurEtage);*/


    MeshBuilder mb;
    EtageResidentiel er1(poly1,hauteur,hauteurEtage,0,0,0);
    EtageResidentiel er2(poly2,hauteur,hauteurEtage,0,0,0);
    EtageResidentiel er3(poly3,hauteur,hauteurEtage,0,0,0);
    Mesh partie1 = mb.generationEtage(&er1);
    Mesh partie2 = mb.generationEtage(&er2);
    Mesh partie3 = mb.generationEtage(&er3);
    partie1.merge(partie2);
    partie1.merge(partie3);

    QVector<std::pair<Batiment*,int>> bats;
    EtageL l(base, hauteur+hauteurEtage, hauteurEtage, hMax-1, shrinkMax, aireMin, poly1, poly2, poly3);

    if(hMax > 1)
    {
        bats.append(std::make_pair(&l, 20));
        partie1.merge(Batiment::getRandomBatiment(bats)->generate());
    }



    return partie1;
}
