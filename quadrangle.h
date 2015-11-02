#ifndef QUADRANGLE_H
#define QUADRANGLE_H
#include "polyangle.h"
#include "vector2d.h"

class Quadrangle : Polyangle
{
private :
    Vector2D a;
    Vector2D b;
    Vector2D c;
    Vector2D d;


public:
    Quadrangle();
    Quadrangle(Vector2D p1, Vector2D p2, Vector2D p3, Vector2D p4) : a(p1), b(p2), c(p3), d(p4){}
    double area();
    double perimetre();
    Polyangle* shrink(const double l);
    Vector2D getA() const;
    void setA(const Vector2D &value);
    Vector2D getB() const;
    void setB(const Vector2D &value);
    Vector2D getC() const;
    void setC(const Vector2D &value);
    Vector2D getD() const;
    void setD(const Vector2D &value);
};

#endif // QUADRANGLE_H
