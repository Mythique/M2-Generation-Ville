#ifndef PLAN_H
#define PLAN_H
#include <QList>
#include "../polyangle.h"
#include "route.h"
#include "quartier.h"
#include "citycenter.h"

class Plan
{
private:
    Polyangle poly;
    Mesh meshBatiments;
    Mesh meshRoute;
    int id;
    QList<std::pair<Vector2D, int>>* pointsRoute;
    CityCenter cityCenter;
public:
    Plan(const Polyangle& p, Mesh& mb, Mesh& mr, int i, QList<std::pair<Vector2D, int>>* pR, const CityCenter& cc);
    void create();
    void divide(const Polyangle &p);
    Mesh getMeshBatiment();
    Mesh getMeshRoute();
    CityCenter getCityCenter();
    bool getFirstPointBetween(const Vector2D& a, const Vector2D& b, float decalage, int &out);

};

#endif // PLAN_H
