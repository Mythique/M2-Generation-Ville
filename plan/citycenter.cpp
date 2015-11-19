#include "citycenter.h"

CityCenter::CityCenter(const Vector2D &c, float infl) : center(c), influence(infl) { }

Vector2D CityCenter::getCenter() const
{
    return center;
}

float CityCenter::getInfluence() const
{
    return influence;
}

