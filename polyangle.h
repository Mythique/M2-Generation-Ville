#ifndef POLYANGLE_H
#define POLYANGLE_H


class Polyangle
{
public:
    Polyangle();
    virtual double area() =0;
    virtual double perimetre() =0;
    virtual Polyangle* shrink(const double l) =0;


};

#endif // POLYANGLE_H
