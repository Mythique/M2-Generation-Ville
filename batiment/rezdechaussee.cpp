#include "rezdechaussee.h"
#include "etage.h"
#include "polyanglehauteur.h"
#include "meshbuilder.h"

RezDeChaussee::RezDeChaussee()
{

}


Mesh RezDeChaussee::generate() const
{
    QVector<PolyangleHauteur> polyangles;
    polyangles << PolyangleHauteur(base, hauteur)
               << PolyangleHauteur(base, hauteur + hauteurRDC);

    MeshBuilder mb;
    Mesh rdcMesh = mb.generationPolyanglesRelies(polyangles);
    Etage etage = Etage(base, hauteur + hauteurRDC, hauteurRDC);
    rdcMesh.merge(etage.generate());
    return rdcMesh;
}
