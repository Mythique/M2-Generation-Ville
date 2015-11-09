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

    RezDeChaussee rdc = RezDeChaussee(p,0,0.5);
    Mesh m = rdc.generate();
    MeshBuilder mb;
    mb.saveMesh("etage.obj", m);

}

