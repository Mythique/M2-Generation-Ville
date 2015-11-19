#include "parcelle.h"
#include "../batiment/rezdechaussee.h"
#include "../batiment/rezdechausseebusiness.h"
#include "../batiment/rezdechausseeresidentiel.h"
#include "../mathutils.h"


void Parcelle::generate(Mesh &m,const CityCenter& cc)
{
    Vector2D center(0,0);
    for(int i = 0; i < poly.getLesPoints().size(); ++i) {
        center += poly.getLesPoints().at(i);
    }
    center /= poly.getLesPoints().size();

    float influence = MathUtils::fonctionQuadratiqueInv(0.0, cc.getInfluence(), center.distanceToPoint2D(cc.getCenter())) + 0.2;

    Batiment* bat = nullptr;
    RezDeChausseeBusiness rdcb(poly,0,3,20*influence,4,20);
    RezDeChausseeResidentiel rdcr(poly,0,3,7*influence,2,20);
    Polyangle circle = poly.getIncircle((int) MathUtils::random(4,6));
    RezDeChausseeResidentiel rdcg = RezDeChausseeResidentiel(circle, 0, 3, 20*influence, 4, 20);
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

Polyangle Parcelle::getPoly()
{
    return poly;
}

