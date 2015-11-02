#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "vector2d.h"
#include "polyangle.h"

class Triangle : Polyangle
{
private :
    Vector2D a;
    Vector2D b;
    Vector2D c;

public:
    Triangle();
    Triangle(Vector2D p1, Vector2D p2, Vector2D p3) : a(p1), b(p2), c(p3){}
    double area();
    double perimetre();
    Polyangle* shrink(const double l);


    Vector2D getA() const;
    void setA(const Vector2D &value);
    Vector2D getB() const;
    void setB(const Vector2D &value);
    Vector2D getC() const;
    void setC(const Vector2D &value);
};


#endif // TRIANGLE_H
