#include "parcelle.h"
#include "../batiment/rezdechaussee.h"
#include "../batiment/rezdechausseebusiness.h"
#include "../batiment/rezdechausseeresidentiel.h"
#include "../mathutils.h"


void Parcelle::generate(Mesh &m)
{
    if(poly.area() < 15 || poly.plusPetitCote() < 5)
        return;
    Batiment* bat = nullptr;
    RezDeChausseeBusiness rdcb(poly,0,3,20,4,20);
    RezDeChausseeResidentiel rdcr(poly,0,3,7,2,20);
    Polyangle circle = poly.getIncircle((int) MathUtils::random(4,6));
    RezDeChausseeResidentiel rdcg = RezDeChausseeResidentiel(circle, 0, 3, 20, 4, 20);
    switch (type) {
    case BUSINESS:
        bat=&rdcb;
        break;
    case HABITATION:
        bat=&rdcr;
        break;
    case GRATTECIEL:
        bat = &rdcg;
        break;
    default:
        break;
    }

    if(bat!=nullptr){
        Mesh me=bat->generate();
        m.merge(me);
    }

}

