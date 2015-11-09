#include <QCoreApplication>
#include "droite.h"
#include "batiment/toit.h"
#include "vector3d.h"
#include "mesh.h"
#include "meshbuilder.h"
#include "batiment/etage.h"
#include <QVector>
#include <time.h>
#include "polyangle.h"
#include "batiment/rezdechaussee.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    srand(time(NULL)+100556440);

    Vector2D p1(0,0);
    Vector2D p2(1,0);
    Vector2D p3(1,1);
    Vector2D p4(0,1);
    Vector2D p5(-0.5,0.5);


    QVector<Vector2D> listePoints;
    listePoints << p1 << p2 << p3 << p4 << p5;

    Polyangle p(listePoints);

    //Etage e = Etage(p, 0, 0.5);

    RezDeChaussee rdc = RezDeChaussee(p,0,0.5);

    Mesh m = rdc.generate();
    MeshBuilder mb;
    mb.saveMesh("etage.obj", m);

    /*Vector2D p1(0.24,4.04);
    Vector2D p2(5.16,7.94);
    Vector2D p3(7.58,1.6);
    Vector2D p4(2.75,0.27);
    //Vector2D p5(2.46,0.9);
    QVector<Vector2D> points;
    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);
    points.push_back(p4);
    //points.push_back(p5);
    Polyangle poly(points);

    std::cout << "aire polyangle  : " <<  poly.area() << std::endl;
    std::cout << "perimetre polyangle  : " << poly.perimetre() << std::endl;

    poly.shrink(-0.5);
    //Triangle t(p1, p2, p3);
    //std::cout << "aire triangle  : " <<  t.area() << std::endl;
    //std::cout << "perimetre triangle  : " << t.perimetre() << std::endl;

    //t.shrink(1.5);

    /*Quadrangle q(p1, p2, p3, p4);
    std::cout << "aire Quadrangle  : " <<  q.area() << std::endl;
    std::cout << "perimetre Quadrangle  : " << q.perimetre() << std::endl;*/

    /*Droite d1(p1, p2-p1);
    Droite d2(p3, p4-p3);
    std::cout << d1.getIntersection(d2) << std::endl;*/

}

