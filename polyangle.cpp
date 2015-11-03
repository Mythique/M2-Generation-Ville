#include "polyangle.h"

QVector<Vector2D> Polyangle::getLesPoints() const
{
    return lesPoints;
}

double Polyangle::area()
{
    double total = 0;
    for(int cpt = 2; cpt < lesPoints.size(); cpt++)
    {
        total += MathUtils::aireTriangle(lesPoints.at(0), lesPoints.at(cpt), lesPoints.at(cpt-1));
    }
    return total;
}

double Polyangle::perimetre()
{
    double total = 0;
    for(int cpt = 0; cpt < lesPoints.size(); cpt++)
    {
        total += lesPoints.at(cpt).distanceToPoint2D(lesPoints.at((cpt+1)%lesPoints.size()));
    }
    return total;
}

Polyangle Polyangle::shrink(const double l)
{
    int length = lesPoints.size();
    QVector<Vector2D> newPoints;
    newPoints.resize(length);

    for(int cpt = 0; cpt <length ; cpt++)
    {
        Vector2D a = lesPoints.at(cpt);
        Vector2D b = lesPoints.at((cpt+1)%length);
        Vector2D c = lesPoints.at((cpt+2)%length);

        Vector2D ab = b-a;
        Vector2D bc = c-b;
        Vector2D ca = c-a;

        //calcul des vecteurs orthogonaux
        Vector2D orthoAB = Vector2D(-ab.y(), ab.x());
        Vector2D orthoBC = Vector2D(-bc.y(), bc.x());

        //on l'inverse si il est dans le mauvais sens
        if(orthoAB*bc < 0)
        {
            orthoAB = -orthoAB;
        }
        if(orthoBC*ca > 0)
        {
            orthoBC = -orthoBC;
        }
        orthoAB.normalize();
        orthoBC.normalize();

        //création des droites afin de récupérer le point d'intersection
        Vector2D aPrime = a + orthoAB * l;
        Vector2D bPrime = b + orthoAB * l;
        Vector2D cPrime;
        Droite aPrimeBPrime(aPrime, bPrime - aPrime);
        bPrime = b + orthoBC * l;
        cPrime = c + orthoBC * l;
        Droite bPrimeCPrime(bPrime, cPrime - bPrime);

        aPrime = aPrimeBPrime.getIntersection(bPrimeCPrime);
        std::cout << aPrime << std::endl;
        newPoints[cpt] = aPrime;
    }
    return Polyangle(newPoints);

}


void Polyangle::setLesPoints(const QVector<Vector2D> &value)
{
    lesPoints = value;
}

Polyangle::Polyangle()
{
    
}

