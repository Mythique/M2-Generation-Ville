#include "polyangle.h"

QVector<Vector2D> Polyangle::getLesPoints() const
{
    return lesPoints;
}

double Polyangle::area()
{
    double total = 0;
    for(int cpt = 2; cpt < lesPoints.size(); cpt++)
    {
        total += MathUtils::aireTriangle(lesPoints.at(0), lesPoints.at(cpt), lesPoints.at(cpt-1));
    }
    return total;
}

double Polyangle::perimetre()
{
    double total = 0;
    for(int cpt = 0; cpt < lesPoints.size(); cpt++)
    {
        total += lesPoints.at(cpt).distanceToPoint2D(lesPoints.at((cpt+1)%lesPoints.size()));
    }
    return total;
}

Polyangle Polyangle::shrink(const double l)
{
    return Polyangle();
}


void Polyangle::setLesPoints(const QVector<Vector2D> &value)
{
    lesPoints = value;
}

Polyangle::Polyangle()
{
    
}

