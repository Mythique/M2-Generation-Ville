#ifndef PARCELLE_H
#define PARCELLE_H
#include "../generateur.h"
#include "../polyangle.h"
#include "../mesh.h"

class Parcelle : public Generateur
{
private:
    Polyangle* poly;
    enum TypeConstruction : int {HABITATION, JARDIN};
    TypeConstruction type;
    //Quartier* quartier;
public:
    Parcelle();
    virtual Mesh generate();
};

#endif // PARCELLE_H
