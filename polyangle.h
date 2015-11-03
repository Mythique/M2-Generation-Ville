#ifndef POLYANGLE_H
#define POLYANGLE_H
#include <QVector>
#include "vector2d.h"
#include "mathutils.h"
#include "droite.h"

class Polyangle
{
protected:
    QVector<Vector2D> lesPoints;

public:
    Polyangle();
    Polyangle(QVector<Vector2D> points) : lesPoints(points){}
    double area();
    double perimetre();
    Polyangle shrink(const double l);
    bool split(Polyangle & p1, Polyangle & p2, Polyangle & route, const Droite & d);

    QVector<Vector2D> getLesPoints() const;
    void setLesPoints(const QVector<Vector2D> &value);
};

#endif // POLYANGLE_H
