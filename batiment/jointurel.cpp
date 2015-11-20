#include "jointurel.h"

JointureL::JointureL(const Polyangle & p, float h, float hE,int hm,int sm,float am, Polyangle p1, Polyangle p2, Polyangle p3):Batiment(p,h, hE, hm,sm,am)
{

}

Mesh JointureL::generate() const
{
    return Mesh();
}

Polyangle JointureL::getPoly2() const
{
    return poly2;
}

void JointureL::setPoly2(const Polyangle &value)
{
    poly2 = value;
}

Polyangle JointureL::getPoly3() const
{
    return poly3;
}

void JointureL::setPoly3(const Polyangle &value)
{
    poly3 = value;
}

Polyangle JointureL::getPoly1() const
{
    return poly1;
}

void JointureL::setPoly1(const Polyangle &value)
{
    poly1 = value;
}
