#include "droite.h"

Vector2D Droite::getIntersection(const Droite& a)
{
    double t = ((d.x()*o.y())+(d.y()*a.o.x())-(d.y()*o.x())-(d.x()*a.o.y()))/((d.x()*a.d.y())-(d.y()*a.d.x()));
    //std::cout << t << std::endl;
    return a.getO()+a.getD()*(t);
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


