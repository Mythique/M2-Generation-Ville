#include "quadrangle.h"

Quadrangle::Quadrangle(const Vector2D &p1, const Vector2D &p2, const Vector2D &p3, const Vector2D &p4)
{
    lesPoints.resize(4);
    lesPoints[0] = p1;
    lesPoints[1] = p2;
    lesPoints[2] = p3;
    lesPoints[3] = p4;
}

double Quadrangle::area()
{
    Vector2D a = lesPoints.at(0);
    Vector2D b = lesPoints.at(1);
    Vector2D c = lesPoints.at(2);
    Vector2D d = lesPoints.at(3);
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
    Vector2D a = lesPoints.at(0);
    Vector2D b = lesPoints.at(1);
    Vector2D c = lesPoints.at(2);
    Vector2D d = lesPoints.at(3);
    return a.distanceToPoint2D(c) + a.distanceToPoint2D(b) + b.distanceToPoint2D(d) + c.distanceToPoint2D(d);
}

Polyangle* Quadrangle::shrink(const double l)
{
    return nullptr;
}


Quadrangle::Quadrangle()
{

}

