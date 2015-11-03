#include "polyangle.h"

QVector<Vector2D> Polyangle::getLesPoints() const
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

