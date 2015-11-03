#include "polyangle.h"

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

}

QVector<Vector2D> Polyangle::getLesAngles() const
{
    return lesPoints;
}

void Polyangle::setLesPoints(const QVector<Vector2D> &value)
{
    lesPoints = value;
}

Polyangle::Polyangle()
{
    
}

