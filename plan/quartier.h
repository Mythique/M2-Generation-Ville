#ifndef QUARTIER_H
#define QUARTIER_H
#include <QList>
#include "../polyangle.h"
#include "../mesh.h"
#include "parcelle.h"

class Quartier
{
private:
    Polyangle poly;
    enum TypeQuartier : int {RESIDENTIEL, MARCHAND};
    TypeQuartier type;
    QList<Parcelle> parcelles;
public:
    Quartier();
    Quartier(Polyangle polya, double tailleTrottoir, double tailleBatiment);
    void generate(QList<Mesh>& meshes);
};

#endif // QUARTIER_H
