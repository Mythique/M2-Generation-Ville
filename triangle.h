#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "vector2d.h"
#include "droite.h"

class Triangle
{
public:
    Triangle();
    Triangle(const Vector2D &p1, const Vector2D &p2, const Vector2D &p3);
    double area();
    double perimetre();
    Triangle* shrink(const double l);
};


#endif // TRIANGLE_H
