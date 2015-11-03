#include <QCoreApplication>
#include "triangle.h"
#include "quadrangle.h"
#include "batiment/toit.h"
#include "vector3d.h"
#include "mesh.h"
#include "meshbuilder.h"
#include "batiment/etage.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Vector3D p1(0,0,0);
    Vector3D p2(1,0,0);
    Vector3D p4(1,0,1);
    Vector3D p3(0,0,1);

    Toit t = Toit(p1, p2, p3, p4, 0.5);
    //Etage e = Etage(p1, p2, p3, p4, 0.5);
    Mesh m = t.generate();
    MeshBuilder mb;
    mb.saveMesh("toit.obj", m);

}

