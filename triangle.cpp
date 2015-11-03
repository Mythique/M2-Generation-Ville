#include "triangle.h"
#include <math.h>

double Triangle::area()
{
    double ab = a.distanceToPoint2D(b);
    double ac = a.distanceToPoint2D(c);
    double cb = c.distanceToPoint2D(b);
    double s = (ab+ac+cb)/2;

    return sqrt(s*(s-ab)*(s-ac)*(s-cb));
}

double Triangle::perimetre()
{
    return a.distanceToPoint2D(c) + a.distanceToPoint2D(b) + c.distanceToPoint2D(b);
}

Polyangle* Triangle::shrink(const double l)
{

}


Vector2D Triangle::getA() const
{
    return a;
}

void Triangle::setA(const Vector2D &value)
{
    a = value;
}

Vector2D Triangle::getB() const
{
    return b;
}

void Triangle::setB(const Vector2D &value)
{
    b = value;
}

Vector2D Triangle::getC() const
{
    return c;
}

void Triangle::setC(const Vector2D &value)
{
    c = value;
}

Triangle::Triangle()
{

}
