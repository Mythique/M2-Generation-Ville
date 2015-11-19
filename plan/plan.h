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
    Mesh meshBatiments;
    Mesh meshRoute;
public:
    Plan(const Polyangle& p, Mesh& mb, Mesh& mr);
    void create( QList<Quartier>& qs, QList<Route>& rs);
    void divide(const Polyangle &p, QList<Quartier>& qs, QList<Route> &routes);
    Mesh getMeshBatiment();
    Mesh getMeshRoute();

};

#endif // PLAN_H
