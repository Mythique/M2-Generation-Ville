#include "parcelle.h"
#include "../batiment/rezdechaussee.h"
#include "../batiment/rezdechausseebusiness.h"
#include "../batiment/rezdechausseeresidentiel.h"


void Parcelle::generate(Mesh &m)
{
    Batiment* bat;
    RezDeChausseeBusiness rdcb(poly,0,3,20,4,10);
    RezDeChausseeResidentiel rdcr(poly,0,3,7,2,10);
    switch (type) {
    case BUSINESS:
        bat=&rdcb;
        break;
    case HABITATION:
        bat=&rdcr;
        break;
    default:
        break;
    }

    if(bat!=nullptr){
        Mesh me=bat->generate();
        m.merge(me);
    }

}

