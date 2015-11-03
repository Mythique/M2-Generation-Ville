#include "polyangle.h"

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

