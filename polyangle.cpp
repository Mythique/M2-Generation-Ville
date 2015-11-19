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
    //std::cout << "debut constructeur" << std::endl;
    //uncross();
    //std::cout << "après uncross" << std::endl;
    //checkSens();
    //std::cout << "après check sens" << std::endl;
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
        Vector2D a = lesPoints.at((cpt-1+length)%length);
        Vector2D b = lesPoints.at((cpt));
        Vector2D c = lesPoints.at((cpt+1)%length);

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

        //std::cout << aPrime << std::endl;
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
        //std::cout << "mauvais sens"<< std::endl;
        for(int i = lesPoints.size()-1; i >=0 ; i--)
        {
            newPoints.push_back(lesPoints[i]);
        }
        lesPoints = newPoints;
    }

}

float Polyangle::plusPetitCote() const
{
    float dist = 0;
    int size = lesPoints.size();
    if(size > 1) {
        Vector3D prec = lesPoints[0];
        Vector3D next;
        for(int i = 1; i <= size; ++i) {
            next = lesPoints[i%size];
            float distTmp = prec.distanceToPoint(next);
            if(dist == 0 || distTmp < dist) {
                dist = distTmp;
            }
            prec = next;
        }
    }
    return dist;
}

bool Polyangle::split(Polyangle & p1, Polyangle & p2, Polyangle & route, const Droite & d, const double largeurDemiRoute) const
{
    //calcul des deux parallèles a ma droite de coupe
    Vector2D orthoAB = Vector2D(-d.getD().y(), d.getD().x());
    Droite para1(d.getO() + orthoAB * largeurDemiRoute, d.getD());
    Droite para2(d.getO() - orthoAB * largeurDemiRoute, d.getD());

    Polyangle pTemp;
    if(!split(p1, pTemp, para1))return false;
    return pTemp.split(route, p2, para2);

}

bool Polyangle::split(Polyangle & p1, Polyangle & p2, const Droite & d) const
{
    //std::cout << "début split" << std::endl;
    //Droite d(dr.getO()-dr.getD()*100000000,dr.getD());
    Vector2D pointIntersection1;
    int iBeforeInter1;
    int iAfterInter1;
    Vector2D pointIntersection2;
    int iBeforeInter2 = -1;
    int iAfterInter2 = -1;

    bool inter2=false;

    for(int i = 0; i < lesPoints.size(); i++)
    {
        Vector2D pointIntersection;
        Vector2D pointCote1 = lesPoints[i];
        Vector2D pointCote2 = lesPoints[(i+1)%lesPoints.size()];
        //std::cout << pointCote1 << std::endl;
        //std::cout << pointCote2 << std::endl;

        Droite cote(pointCote1, (pointCote2-pointCote1));
        if(d.getIntersection(cote, pointIntersection))
        {
            if(pointCote1.distanceToPoint2DSquared(pointIntersection) < pointCote1.distanceToPoint2DSquared(pointCote2)
                    && pointCote2.distanceToPoint2DSquared(pointIntersection) < pointCote1.distanceToPoint2DSquared(pointCote2))
            {
                if(!inter2)
                {
                    pointIntersection1 = pointIntersection;
                    iBeforeInter1=i;
                    iAfterInter1 = (i+1)%lesPoints.size();
                    inter2=true;
                }
                else
                {
                    pointIntersection2 = pointIntersection;
                    iBeforeInter2=i;
                    iAfterInter2 = (i+1)%lesPoints.size();
                    break;
                }
            }
        }
    }
    if(!inter2)
    {
        return false;
    }

    QVector<Vector2D> lesPoints1;
    if(iAfterInter1 <= iBeforeInter2)
    {
        for(int i = iAfterInter1; i <=  iBeforeInter2; i++)
        {
            lesPoints1.push_back(lesPoints[i]);
        }
    }
    else
    {
        for(int i = iAfterInter1; i <  lesPoints.size(); i++)
        {
            lesPoints1.push_back(lesPoints[i]);
        }
        for(int i = 0; i < iBeforeInter2; i++)
        {
            lesPoints1.push_back(lesPoints[i]);
        }
    }
    lesPoints1.push_back(pointIntersection2);
    lesPoints1.push_back(pointIntersection1);



    QVector<Vector2D> lesPoints2;
    if(iAfterInter2 <= iBeforeInter1)
    {
        for(int i = iAfterInter2; i <= iBeforeInter1; i++)
        {
            lesPoints2.push_back(lesPoints[i]);
        }
    }
    else
    {
        for(int i = iAfterInter2; i < lesPoints.size(); i++)
        {
            lesPoints2.push_back(lesPoints[i]);
        }
        for(int i = 0; i <= iBeforeInter1; i++)
        {
            lesPoints2.push_back(lesPoints[i]);
        }
    }
    lesPoints2.push_back(pointIntersection1);
    lesPoints2.push_back(pointIntersection2);

    Vector2D orth(-d.getD().y(), d.getD().x());
    Vector2D point1(lesPoints1[0]- d.getO());


    //if(d.getD().distanceToPoint2DSquared(pointIntersection1) > d.getD().distanceToPoint2DSquared(pointIntersection2))
    if(orth*point1 > 0)
    {
        p1 = Polyangle(lesPoints1);
        p2 = Polyangle(lesPoints2);
    }
    else
    {
        p2 = Polyangle(lesPoints1);
        p1 = Polyangle(lesPoints2);
    }
    return true;

}

std::pair<int, int> Polyangle::getHighestPair()
{
    std::pair<int, int> indices;
    double max = 0;
    if(lesPoints.length()> 3)
    {
        for(int i = 0; i < (lesPoints.length()+1)/2; i++)
        {
            double longueur = lesPoints[i].distanceToPoint2D(lesPoints[(i+1)%lesPoints.size()]) + lesPoints[(i+2)%lesPoints.size()].distanceToPoint2D(lesPoints[(i+3)%lesPoints.size()]);
            if(longueur > max)
            {
                indices = std::make_pair(i, (i+2)%lesPoints.size());
                max = longueur;
            }
        }
    }
    else
    {
        for(int i = 0; i < lesPoints.length(); i++)
        {
            double longueur = lesPoints[i].distanceToPoint2D(lesPoints[(i+1)%lesPoints.size()]) + lesPoints[(i+1)%lesPoints.size()].distanceToPoint2D(lesPoints[(i+2)%lesPoints.size()]);
            if(longueur > max)
            {
                indices = std::make_pair(i, (i+1)%lesPoints.size());
                max = longueur;
            }
        }
    }
    return indices;
}

QVector<Vector2D> Polyangle::getLesPoints() const
{
    return lesPoints;
}

void Polyangle::setLesPoints(const QVector<Vector2D> &value)
{
    lesPoints = value;
}



