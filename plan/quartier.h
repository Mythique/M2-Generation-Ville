#ifndef QUARTIER_H
#define QUARTIER_H
#include <QList>
#include "../polyangle.h"
#include "../mesh.h"
#include "parcelle.h"

class Quartier
{
public :
    enum TypeQuartier : int {RESIDENTIEL, MARCHAND};
private:
    Polyangle poly;
    TypeQuartier type;
    QList<Parcelle> parcelles;
public:

    Quartier();
    Quartier(Polyangle polya, double tailleTrottoir, double tailleBatiment);


    Quartier(const Polyangle& p, TypeQuartier tq);

    void generate(QList<Mesh>& meshes);
    const Polyangle getPoly();
};

#endif // QUARTIER_H
