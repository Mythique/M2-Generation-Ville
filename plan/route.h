#ifndef ROUTE_H
#define ROUTE_H
#include "../polyangle.h"
#include "../generateur.h"

class Route
{
private:
    Polyangle poly;
public:
    Route(Polyangle q);
    Polyangle getQuad();
    void generate(Mesh &m);


};

#endif // ROUTE_H
