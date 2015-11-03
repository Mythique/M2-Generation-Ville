#include "polyangle.h"

double Polyangle::area()
{
    double total = 0;
    for(int cpt = 2; cpt < lesAngles.size(); cpt++)
    {
        total += MathUtils::aireTriangle(lesAngles.at(0), lesAngles.at(cpt), lesAngles.at(cpt-1));
    }
    return total;
}

double Polyangle::perimetre()
{
    double total = 0;
    for(int cpt = 0; cpt < lesAngles.size(); cpt++)
    {
        total += lesAngles.at(cpt).distanceToPoint2D(lesAngles.at((cpt+1)%lesAngles.size()));
    }
    return total;
}

Polyangle Polyangle::shrink(const double l)
{

}

QVector<Vector2D> Polyangle::getLesAngles() const
{
    return lesAngles;
}

void Polyangle::setLesAngles(const QVector<Vector2D> &value)
{
    lesAngles = value;
}

Polyangle::Polyangle()
{
    
}

