#include "cheminee.h"
#include "meshbuilder.h"
#include "polyanglehauteur.h"

Mesh Cheminee::generate() const
{
    Polyangle baseShrinked = base.shrink(base.plusPetitCote()/10);
    QVector<Vector2D> pointsBase = baseShrinked.getLesPoints();
    Vector2D dirp1p2 = (pointsBase[1] - pointsBase[0]).normalized();
    Vector2D p1 = pointsBase[0];
    Vector2D p2 = p1 + dirp1p2 * base.plusPetitCote()/10;

    Vector2D p1p2 = p2 - p1;

    Vector2D p3 = p2 + Vector2D(-p1p2.y(), p1p2.x());
    Vector2D p4 = p1 + Vector2D(-p1p2.y(), p1p2.x());
    QVector<Vector2D> listePoints;
    listePoints << p1 << p2 << p3 << p4;
    Polyangle baseCheminee(listePoints);

    QVector <PolyangleHauteur> polyangles;
    polyangles << PolyangleHauteur(baseCheminee, hauteur)
               << PolyangleHauteur(baseCheminee, hauteur + hauteurEtage);

    MeshBuilder mb;
    return mb.generationPolyanglesRelies(polyangles);
}
