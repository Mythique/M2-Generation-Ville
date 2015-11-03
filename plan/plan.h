#ifndef PLAN_H
#define PLAN_H
#include <QList>
#include "../polyangle.h"
#include "route.h"
#include "quartier.h"

class Plan
{
private:
    Polyangle* poly;
public:
    Plan(Polyangle * const p);
    void create(QList<Quartier>& qs, QList<Route>& rs);

};

#endif // PLAN_H
