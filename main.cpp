
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
#include "plan/plan.h"
#include "plan/quartier.h"
#include "plan/route.h"
#include <QTime>
#include "batiment/jardin.h"


int main(int argc, char *argv[])
{
    srand(time(NULL));


    QVector<Vector2D> liste1, liste2, liste3, liste4, liste5, liste6, liste7, liste8;

    Vector2D p1(0,0), p2(200,200), p3(-200,200), p4(200,800), p5(-200,850),
            p6(300,800), p7(750,900), p8(850,200), p9(300,200), p10(100,-200), p11(850,-200), p12(700,-800), p13(100,-850),
            p14(-100,-200), p15(-100, -850), p16(-750, -800), p17 (-900,-200), p18(-900, 200), p19(-300, 200), p20(-300, 850), p21(-800, 1000);

    liste1 << p1 << p2 << p3;
    liste2 << p2 << p4 << p5 << p3;
    liste3 << p9 << p8 << p7 << p6;
    liste4 << p11 << p8 << p9 << p10;
    liste5 << p12 << p11 << p10 << p13;
    liste6 << p15 << p14 << p17 << p16;
    liste7 << p14 << p19 << p18 << p17;
    liste8 << p19 << p20 << p21 << p18;

    Polyangle poly1(liste1), poly2(liste2), poly3(liste3), poly4(liste4), poly5(liste5), poly6(liste6), poly7(liste7), poly8(liste8);
    Mesh m1, m1r, m2, m2r, m3, m3r, m4, m4r, m5, m5r, m6, m6r, m7, m7r, m8, m8r;
    QList<std::pair<Vector2D, int>> pointsRoute;
    Vector2D center(0,0);
    CityCenter cc(center, 500);
    Plan pl1(poly1, m1, m1r, 1, &pointsRoute, cc), pl2(poly2, m2, m2r, 2, &pointsRoute, cc), pl3(poly3, m3, m3r, 3, &pointsRoute, cc),
            pl4(poly4, m4, m4r, 4, &pointsRoute, cc), pl5(poly5, m5, m5r, 5, &pointsRoute, cc), pl6(poly6, m6, m6r, 6, &pointsRoute, cc),
            pl7(poly7, m7, m7r, 7, &pointsRoute, cc), pl8(poly8, m8, m8r, 8, &pointsRoute, cc);

    QTime t;
    t.restart();
    pl1.create();
    std::cout << " 1 - " << t.restart() << std::endl;
    pl2.create();
    std::cout << " 2 - " << t.restart() << std::endl;
    pl3.create();
    std::cout << " 3 - " << t.restart() << std::endl;
    pl4.create();
    std::cout << " 4 - " << t.restart() << std::endl;
    pl5.create();
    std::cout << " 5 - " << t.restart() << std::endl;
    pl6.create();
    std::cout << " 6 - " << t.restart() << std::endl;
    pl7.create();
    std::cout << " 7 - " << t.restart() << std::endl;
    pl8.create();
    std::cout << " 8 - " << t.restart() << std::endl;


    MeshBuilder mb;

    Mesh routeTotal;

    routeTotal.merge(pl1.getMeshRoute());
    routeTotal.merge(pl2.getMeshRoute());
    routeTotal.merge(pl3.getMeshRoute());
    routeTotal.merge(pl4.getMeshRoute());
    routeTotal.merge(pl5.getMeshRoute());
    routeTotal.merge(pl6.getMeshRoute());
    routeTotal.merge(pl7.getMeshRoute());
    routeTotal.merge(pl8.getMeshRoute());


    mb.saveMesh("plan1.obj", pl1.getMeshBatiment());

    mb.saveMesh("plan2.obj", pl2.getMeshBatiment());

    mb.saveMesh("plan3.obj", pl3.getMeshBatiment());

    mb.saveMesh("plan4.obj", pl4.getMeshBatiment());

    mb.saveMesh("plan5.obj", pl5.getMeshBatiment());

    mb.saveMesh("plan6.obj", pl6.getMeshBatiment());

    mb.saveMesh("plan7.obj", pl7.getMeshBatiment());

    mb.saveMesh("plan8.obj", pl8.getMeshBatiment());

    mb.saveMesh("routes.obj", routeTotal);




}

