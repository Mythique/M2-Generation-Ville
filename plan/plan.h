#ifndef PLAN_H
#define PLAN_H
#include <QList>
#include "../polyangle.h"
#include "route.h"
#include "quartier.h"

class Plan
{
private:
    Polyangle poly;
    Mesh mesh;
public:
    Plan(const Polyangle& p, Mesh& m);
    void create( QList<Quartier>& qs, QList<Route>& rs);
    void divide(const Polyangle &p, QList<Quartier>& qs, QList<Route> &routes);
    Mesh getMesh();

};

#endif // PLAN_H
