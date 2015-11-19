#ifndef PARCELLE_H
#define PARCELLE_H
#include "../generateur.h"
#include "../polyangle.h"
#include "../mesh.h"
#include "citycenter.h"

class Parcelle //: public Generateur
{
public :
    enum TypeConstruction : int {HABITATION, JARDIN, BUSINESS, GRATTECIEL};
private:
    Polyangle poly;

    TypeConstruction type;
public:

    Parcelle(Polyangle polya, TypeConstruction t) : poly(polya), type(t){}
    void generate(Mesh &m, const CityCenter &cc);
    Polyangle getPoly();
};

#endif // PARCELLE_H
