#include "polyangle.h"


Polyangle::Polyangle()
{

}

Polyangle::Polyangle(const Polyangle &poly)
{
    lesPoints = poly.getLesPoints();
}

Polyangle::Polyangle(QVector<Vector2D> points) : lesPoints(points)
{
    uncross();
    checkSens();
}


double Polyangle::area() const
{
    double total = 0;
    for(int cpt = 2; cpt < lesPoints.size(); cpt++)
    {
        total += MathUtils::aireTriangle(lesPoints.at(0), lesPoints.at(cpt), lesPoints.at(cpt-1));
    }
    return total;
}

double Polyangle::perimetre() const
{
    double total = 0;
    for(int cpt = 0; cpt < lesPoints.size(); cpt++)
    {
        total += lesPoints.at(cpt).distanceToPoint2D(lesPoints.at((cpt+1)%lesPoints.size()));
    }
    return total;
}

Polyangle Polyangle::shrink(const double l) const
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

        aPrimeBPrime.getIntersection(bPrimeCPrime, aPrime);

        std::cout << aPrime << std::endl;
        newPoints[cpt] = aPrime;
    }
    return Polyangle(newPoints);

}

void Polyangle::uncross() {


    //cout << p[0] << p[1] << p[2] << p[3] << p[4] << p[5] << endl;
        bool test = false;
        for(int i = 0; i < lesPoints.size(); ++i) {
            Vector2D ab = lesPoints.at((i+1)%lesPoints.size())-lesPoints.at(i);
            Vector2D cd = lesPoints.at((i+3)%lesPoints.size())-lesPoints.at((i+2)%lesPoints.size());

            Vector2D bc = lesPoints.at((i+2)%lesPoints.size())-lesPoints.at((i+1)%lesPoints.size());
            Vector2D da = lesPoints.at(i)-lesPoints.at((i+3)%lesPoints.size());

            double crossABCD = ab*cd;
            double crossBCDA = bc*da;
            if(crossBCDA > 0)
            {
                Vector2D temp = lesPoints[(i+1)%lesPoints.size()];
                lesPoints[(i+1)%lesPoints.size()] = lesPoints[(i+2)%lesPoints.size()];
                lesPoints[(i+2)%lesPoints.size()] = temp;

                /*int tmp = p[(i+1)%p.size()];
                p[(i+1)%p.size()] = p[(i+2)%p.size()];
                p[(i+2)%p.size()] = tmp;//*/

                test = true;

            }


            if(!test)
            {
                if(crossABCD > 0)
                {
                    test = true;
                    Vector2D temp = lesPoints[(i+2)%lesPoints.size()];
                    lesPoints[(i+2)%lesPoints.size()] = lesPoints[(i+3)%lesPoints.size()];
                    lesPoints[(i+3)%lesPoints.size()] = temp;

                    /*int tmp = p[(i+2)%p.size()];
                    p[(i+2)%p.size()] = p[(i+3)%p.size()];
                    p[(i+3)%p.size()] = tmp;//*/

                }
            }

            if(crossBCDA > 0 || crossABCD > 0) {
                break;
            }
        }
        if(test) {
            uncross();
        }

}


void Polyangle::checkSens()
{
    QVector<Vector2D> newPoints;
    Vector3D a = lesPoints[0];
    Vector3D b = lesPoints[1];
    Vector3D c = lesPoints[2];
    Vector3D orientation = (c-b)^(a-b);
    if (orientation.z() < 0)
    {
        std::cout << "mauvais sens"<< std::endl;
        for(int i = lesPoints.size()-1; i >=0 ; i--)
        {
            newPoints.push_back(lesPoints[i]);
        }
        lesPoints = newPoints;
    }

}

bool Polyangle::split(Polyangle & p1, Polyangle & p2, Polyangle & route, const Droite & d, const double largeurDemiRoute) const
{
    /*bool b = false;
    for(int i = 0; i < lesPoints.size(); i++)
    {
        Droite d1(lesPoints[i+1], lesPoints[i]);
        Vector2D pointIntersection;
        if(d.getIntersection(d1, pointIntersection))
        {
            b =true;
        }
    }
    return b;*/
    return false;
}

QVector<Vector2D> Polyangle::getLesPoints() const
{
    return lesPoints;
}

void Polyangle::setLesPoints(const QVector<Vector2D> &value)
{
    lesPoints = value;
}



