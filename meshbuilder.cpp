#include "meshbuilder.h"
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#ifndef fmin
#define fmin(a,b) a<b?a:b
#endif
#define PI 3.14159265358979323846
using namespace std;
MeshBuilder::MeshBuilder()
{
}

void MeshBuilder::saveMesh(const string &nom, const Mesh &mesh) const
{
    ofstream out;
    out.open(nom);

    out << fixed << setprecision(2);
    out << "o "<<mesh.getNom().toStdString()<<"\n";
    for(QList<Vector3D>::const_iterator itVect = mesh.getGeom().begin(); itVect != mesh.getGeom().end(); ++itVect) {
    out << "v " << itVect->x() << " " << itVect->y() << " " << itVect->z() << "\n";
    }
    out << "\n";


    for(QList<Vector3D>::const_iterator itNorm = mesh.getNorm().begin(); itNorm != mesh.getNorm().end(); ++itNorm) {
    out << "vn " << itNorm->x() << " " << itNorm->y() << " " << itNorm->z() << "\n";
    }
    out << "\n";

    out << "vt 0.0 0.0 \n\n";

    for(QList<int>::const_iterator it = mesh.getTopo().begin(); it != mesh.getTopo().end();) {
    out << "f ";
    for(int i = 0; i < 3; i++) {
    int face = (*(it++)) + 1;
    int texture = (*(it++)) + 1;
    int normale = (*(it++)) + 1;
    out << face << "/" << texture << "/" << normale << " ";
    }
    out << "\n";
    }

    out.close();
}

// Ne prend pas les textures en compte
Mesh MeshBuilder::loadMesh(const QString &nom) const
{
    QList<Vector3D> geoms;
    QList<Vector3D> norms;
    QList<int> topos;
    QFile file(nom);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    QString read;

    while(true) {
        read = in.readLine();
        QStringList l = read.split(" ");
        if(l.at(0) == "v") {
            Vector3D tmp(l.at(1).toDouble(), l.at(2).toDouble(), l.at(3).toDouble());
            geoms.append(tmp);
        }
        if(l.at(0) == "vn") {
            Vector3D tmp(l.at(1).toDouble(), l.at(2).toDouble(), l.at(3).toDouble());
            norms.append(tmp);
        }
        if(l.at(0) == "f") {
            for(int i = 1; i < 4; ++i){
                QStringList l2 = l.at(i).split("/");
                for(int j = 0; j < l2.length(); ++j) {
                    topos.append(l2.at(j).toInt()-1);
                }
            }
        }
        if(in.atEnd()) {
            break;
        }
    }

    Mesh res(geoms, topos, norms, nom);
    std::cout << nom.toStdString() << " chargé" << std::endl;
    return res;
}

MeshBuilder::~MeshBuilder()
{

}

Mesh MeshBuilder::generationPolyanglesRelies(const QVector<PolyangleHauteur> &polyangles) const
{
    QList<Vector3D> geom;
    QList<int> topo;
    QList<Vector3D> normales;

    int nbPoly = polyangles.size();
    int nbPoints = polyangles[0].getPolyangle().getLesPoints().size();

    // Géométrie
    for (int i = 0; i < nbPoints; i++)
    {
        for (int j = 0; j < nbPoly; j++)
        {
            geom << Vector3D(polyangles[j].getPolyangle().getLesPoints()[i], polyangles[j].getHauteur());
        }
    }

    int cptNormales = 0;

    // Topologie
    for (int i = 0; i < nbPoints*nbPoly; i++)
    {
        if ((i+1)%nbPoly != 0)
        {
            int p1, p2, p3, p4;
            p1 = i;
            p2 = (i + nbPoly) % (nbPoly*nbPoints);
            p3 = i + 1;
            p4 = p2 + 1;

            Vector3D n = (geom[p3]-geom[p2])^(geom[p1]-geom[p2]);
            n.normalize();
            normales << n;

            // indice point, indice texture, indice normale
            // Premier triangle
            topo << p1 << 0 << cptNormales
                 << p2 << 0 << cptNormales
                 << p3 << 0 << cptNormales;
            // Second triangle
            topo << p3 << 0 << cptNormales
                 << p2 << 0 << cptNormales
                 << p4 << 0 << cptNormales;
            cptNormales++;

        }
    }

    // Topologie plafond
    for (int i = 1; i < nbPoints-1; i++)
    {
        int p1, p2, p3;
        p1 = nbPoly-1;
        p2 = nbPoly-1 + i*nbPoly;
        p3 = nbPoly-1 + (i+1)*nbPoly;

        Vector3D n(0,0,1);
        normales << n;
        topo << p1 << 0 << cptNormales
             << p2 << 0 << cptNormales
             << p3 << 0 << cptNormales;
        cptNormales++;
    }

    return Mesh(geom, topo, normales, "PolyanglesRelies");
}

Mesh MeshBuilder::generationCone(const PolyangleHauteur &poly, const float hauteurCone)
{
    QList<Vector3D> geom;
    QList<int> topo;
    QList<Vector3D> normales;

    int nbPoints = poly.getPolyangle().getLesPoints().size();

    // Géométrie
    Vector3D e(0,0,0);
    for (int i = 0; i < nbPoints; i++)
    {
        e += Vector3D(poly.getPolyangle().getLesPoints()[i], poly.getHauteur() + hauteurCone);
        geom << Vector3D(poly.getPolyangle().getLesPoints()[i], poly.getHauteur());
    }
    e /= nbPoints;
    geom << e;

    // Topologie
    for (int i = 0; i < nbPoints; i++)
    {
        int p1, p2, p3;
        p1 = nbPoints;
        p2 = i;
        p3 = (i+1)%nbPoints;

        Vector3D n = (geom[p1]-geom[p3])^(geom[p2]-geom[p3]);
        n.normalize();

        normales.push_back(n);

        // indice point, indice texture, indice normale
        topo << p1 << 0 << i
             << p2 << 0 << i
             << p3 << 0 << i;
    }

    return Mesh(geom, topo, normales, "cone");
}

Mesh MeshBuilder::generationCone(const Vector3D &centre, const float hauteurCone, const int definition, const float rayon)
{
    float pi = 3.14159265358979323846;

    QList<Vector3D> geom;
    QList<int> topo;
    QList<Vector3D> normales;
    Vector3D pointe = Vector3D(centre.x(), centre.y(), centre.z() + hauteurCone);
    for (int i=0; i < definition; i++)
    {
        float x = cos(2*pi*i/definition)*rayon;
        float y = sin(2*pi*i/definition)*rayon;
        geom << centre + Vector3D(x, y, 0);
    }
    geom << pointe;

    for (int i = 0; i < definition; i++)
    {
        int p1, p2, p3;
        p1 = definition;
        p2 = i;
        p3 = (i+1)%definition;

        Vector3D n = (geom[p1]-geom[p3])^(geom[p2]-geom[p3]);
        n.normalize();

        normales.push_back(n);

        // indice point, indice texture, indice normale
        topo << p1 << 0 << i
             << p2 << 0 << i
             << p3 << 0 << i;
    }

    return Mesh(geom, topo, normales, "cone");

}

Mesh MeshBuilder::generationEtage(const Batiment *etage) const
{
    Polyangle baseShrinked = etage->getBase().shrink(etage->getBase().plusPetitCote()/20);

    QVector<PolyangleHauteur> polyangles;
    polyangles << PolyangleHauteur(baseShrinked, etage->getHauteur())
               << PolyangleHauteur(baseShrinked, etage->getHauteur() + etage->getHauteurEtage()/10)
               << PolyangleHauteur(etage->getBase(), etage->getHauteur() + etage->getHauteurEtage()/10)
               << PolyangleHauteur(etage->getBase(), etage->getHauteur() + etage->getHauteurEtage());

    return generationPolyanglesRelies(polyangles);
}
