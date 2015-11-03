#ifndef POLYANGLE_H
#define POLYANGLE_H
#include <QVector>
#include "vector2d.h"
#include "mathutils.h"

class Polyangle
{
protected:
    QVector<Vector2D> lesAngles;

public:
    Polyangle();
    Polyangle(QVector<Vector2D> angles) : lesAngles(angles){}
    double area();
    double perimetre();
    Polyangle shrink(const double l);


    QVector<Vector2D> getLesAngles() const;
    void setLesAngles(const QVector<Vector2D> &value);
};

#endif // POLYANGLE_H
