#ifndef ROUTE_H
#define ROUTE_H
#include "../quadrangle.h"
#include "../generateur.h"

class Route : public Generateur
{
private:
    Quadrangle quad;
public:
    Route(Quadrangle q);
    Quadrangle getQuad();


};

#endif // ROUTE_H
