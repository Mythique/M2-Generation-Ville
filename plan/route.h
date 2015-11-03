#ifndef ROUTE_H
#define ROUTE_H
#include "../polyangle.h"
#include "../generateur.h"

class Route : public Generateur
{
private:
    Polyangle quad;
public:
    Route(Polyangle q);
    Polyangle getQuad();


};

#endif // ROUTE_H
