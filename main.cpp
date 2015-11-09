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

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    srand(time(NULL));


    Vector2D p1(4.14,2.64);
    Vector2D p2(11,4);
    Vector2D p3(14.32,-1.46);
    Vector2D p4(2.44,-6.24);
    //Vector2D p5(-0.5,0.5);

    Droite d(Vector2D(4.28,4.5), Vector2D(1.06,-0.86));

    QVector<Vector2D> listePoints;
    listePoints << p1 << p4 << p3 << p2;
    Polyangle p(listePoints);

    Polyangle poly1;
    Polyangle poly2;
    Polyangle route;
    p.split(poly1, poly2, route, d, 2.4);




    /*Etage e = Etage(p, 0, 0.5);
    Mesh m = e.generate();
    MeshBuilder mb;
    mb.saveMesh("etage.obj", m);*/

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

