#ifndef QUADRANGLE_H
#define QUADRANGLE_H
#include "polyangle.h"
#include "vector2d.h"

class Quadrangle : public Polyangle
{

public:
    Quadrangle();
    Quadrangle(const Vector2D &p1, const Vector2D &p2, const Vector2D &p3, const Vector2D& p4);
    double area();
    double perimetre();
    Polyangle* shrink(const double l);

};

#endif // QUADRANGLE_H
