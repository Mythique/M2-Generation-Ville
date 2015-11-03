#include "quadrangle.h"

double Quadrangle::area()
{
    double ab = a.distanceToPoint2D(b);
    double ac = a.distanceToPoint2D(c);
    double cb = c.distanceToPoint2D(b);
    double bd = b.distanceToPoint2D(d);
    double cd = c.distanceToPoint2D(d);
    double s1 = (ab+ac+cb)/2;
    double s2 = (bd+cd+cb)/2;

    return sqrt(s1*(s1-ab)*(s1-ac)*(s1-cb))+sqrt(s2*(s2-bd)*(s2-cd)*(s2-cb));
}

double Quadrangle::perimetre()
{
    return a.distanceToPoint2D(c) + a.distanceToPoint2D(b) + b.distanceToPoint2D(d) + c.distanceToPoint2D(d);
}

Polyangle* Quadrangle::shrink(const double l)
{

}

Vector2D Quadrangle::getA() const
{
    return a;
}

void Quadrangle::setA(const Vector2D &value)
{
    a = value;
}

Vector2D Quadrangle::getB() const
{
    return b;
}

void Quadrangle::setB(const Vector2D &value)
{
    b = value;
}

Vector2D Quadrangle::getC() const
{
    return c;
}

void Quadrangle::setC(const Vector2D &value)
{
    c = value;
}

Vector2D Quadrangle::getD() const
{
    return d;
}

void Quadrangle::setD(const Vector2D &value)
{
    d = value;
}

Quadrangle::Quadrangle()
{

}

