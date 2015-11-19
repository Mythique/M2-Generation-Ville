#ifndef QUARTIER_H
#define QUARTIER_H
#include <QList>
#include "../polyangle.h"
#include "../mesh.h"
#include "parcelle.h"
#include "citycenter.h"

class Quartier
{
public :
    enum TypeQuartier : int {RESIDENTIEL, MARCHAND, GRATTECIEL, CHAMPS};
private:
    Polyangle poly;
    TypeQuartier type;
    QList<Parcelle> parcelles;
public:

    Quartier();
    Quartier(Polyangle polya, double tailleTrottoir, double tailleBatiment, const TypeQuartier tq);

    void generate(Mesh& mesh, const CityCenter &cc);
    const Polyangle getPoly();
};

#endif // QUARTIER_H
