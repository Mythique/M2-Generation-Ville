#include "droite.h"

bool Droite::getIntersection(const Droite& a, Vector2D &point)
{
    bool b = false;
    //droites non paralleles
    if(std::abs(a.d.x()/a.d.y()- d.x()/d.y()) > 0.0001)
    {
        double t = ((d.x()*o.y())+(d.y()*a.o.x())-(d.y()*o.x())-(d.x()*a.o.y()))/((d.x()*a.d.y())-(d.y()*a.d.x()));
        point = a.getO()+a.getD()*(t);
        b = true;
    }

    return b;
}


Vector2D Droite::getO() const
{
    return o;
}

void Droite::setO(const Vector2D &value)
{
    o = value;
}

Vector2D Droite::getD() const
{
    return d;
}

void Droite::setD(const Vector2D &value)
{
    d = value;
}

Droite::Droite()
{

}


