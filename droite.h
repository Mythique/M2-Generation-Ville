#ifndef DROITE_H
#define DROITE_H
#include "vector2d.h"

class Droite
{
    private:
        Vector2D o;
        Vector2D d;
    public:
        Droite();
        Droite(Vector2D p1, Vector2D p2) : o(p1), d(p2.normalized()){}
        Vector2D getIntersection(const Droite& a);

        Vector2D getO() const;
        void setO(const Vector2D &value);
        Vector2D getD() const;
        void setD(const Vector2D &value);
};

#endif // DROITE_H
