#ifndef CITYCENTER_H
#define CITYCENTER_H
#include "../vector2d.h"

class CityCenter
{
private :
    Vector2D center;
    float influence;
public:
    CityCenter(const Vector2D& c, float infl);
    Vector2D getCenter() const;
    float getInfluence() const;

};


#endif // CITYCENTER_H
