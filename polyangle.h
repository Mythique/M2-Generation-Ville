#ifndef POLYANGLE_H
#define POLYANGLE_H
#include <QVector>
#include "vector2d.h"

class Polyangle
{
protected:
    QVector<Vector2D> lesAngles;

public:
    Polyangle();
    virtual double area() =0;
    virtual double perimetre() =0;
    virtual Polyangle* shrink(const double l) =0;


    QVector<Vector2D> getLesAngles() const;
    void setLesAngles(const QVector<Vector2D> &value);
};

#endif // POLYANGLE_H
