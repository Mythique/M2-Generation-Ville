#include "triangle.h"
#include <math.h>

Triangle::Triangle(const Vector2D& p1, const Vector2D& p2, const Vector2D& p3)
{
    lesAngles.resize(3);
    lesAngles[0] = p1;
    lesAngles[1] = p2;
    lesAngles[2] = p3;
}

double Triangle::area()
{
    Vector2D a = lesAngles.at(0);
    Vector2D b = lesAngles.at(1);
    Vector2D c = lesAngles.at(2);
    double ab = a.distanceToPoint2D(b);
    double ac = a.distanceToPoint2D(c);
    double cb = c.distanceToPoint2D(b);
    double s = (ab+ac+cb)/2;

    return sqrt(s*(s-ab)*(s-ac)*(s-cb));
}

double Triangle::perimetre()
{
    Vector2D a = lesAngles.at(0);
    Vector2D b = lesAngles.at(1);
    Vector2D c = lesAngles.at(2);
    return a.distanceToPoint2D(c) + a.distanceToPoint2D(b) + c.distanceToPoint2D(b);
}

Polyangle* Triangle::shrink(const double l)
{

    Vector2D a = lesAngles.at(0);
    Vector2D b = lesAngles.at(1);
    Vector2D c = lesAngles.at(2);
    Vector2D orthoAB;
    Vector2D orthoBC;
    Vector2D orthoCA;

    Vector2D ab = b-a;
    Vector2D bc = c-b;
    Vector2D ca = c-a;

    //récupération d'un vecteur orthogonal à AB

    orthoAB = Vector2D(-ab.y(), ab.x());

    //on l'inverse si il est dans le mauvais sens
    if(orthoAB*bc < 0)
    {
        orthoAB = -orthoAB;
    }

    //récupération d'un vecteur orthogonal à BC

    orthoBC = Vector2D(-bc.y(), bc.x());

    //on l'inverse si il est dans le mauvais sens
    if(orthoBC*ca > 0)
    {
        orthoBC = -orthoBC;
    }

    //récupération d'un vecteur orthogonal à CA

    orthoCA = Vector2D(-ca.y(), ca.x());

    //on l'inverse si il est dans le mauvais sens
    if(orthoCA*ab < 0)
    {
        orthoCA = -orthoCA;
    }

    orthoAB.normalize();
    orthoBC.normalize();
    orthoCA.normalize();
    //std::cout << orthoAB << std::endl;
    //std::cout << orthoBC << std::endl;
    //std::cout << orthoCA << std::endl;

    Vector2D aPrime = a + orthoAB * l;
    Vector2D bPrime = b + orthoAB * l;
    Vector2D cPrime;

    //std::cout << aPrime << std::endl;
    //std::cout << bPrime << std::endl;
    Droite aPrimeBPrime(aPrime, bPrime - aPrime);

    bPrime = b + orthoBC * l;
    cPrime = c + orthoBC * l;

    //std::cout << bPrime << std::endl;
    //std::cout << cPrime << std::endl;
    Droite bPrimeCPrime(bPrime, cPrime - bPrime);

    cPrime = c + orthoCA * l;
    aPrime = a + orthoCA * l;

    //std::cout << aPrime << std::endl;
    //std::cout << cPrime << std::endl;
    Droite cPrimeAPrime(cPrime, aPrime - cPrime);

    aPrime = aPrimeBPrime.getIntersection(cPrimeAPrime);
    bPrime = bPrimeCPrime.getIntersection(aPrimeBPrime);
    cPrime = cPrimeAPrime.getIntersection(bPrimeCPrime);

    std::cout << aPrime << std::endl;
    std::cout << bPrime << std::endl;
    std::cout << cPrime << std::endl;

    return new Triangle(aPrime, bPrime, cPrime);
}

Triangle::Triangle()
{

}
