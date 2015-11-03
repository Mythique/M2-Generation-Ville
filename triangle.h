#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "vector2d.h"
#include "polyangle.h"
#include "droite.h"

class Triangle : Polyangle
{
public:
    Triangle();
    Triangle(const Vector2D &p1, const Vector2D &p2, const Vector2D &p3);
    double area();
    double perimetre();
    Polyangle* shrink(const double l);
};


#endif // TRIANGLE_H
