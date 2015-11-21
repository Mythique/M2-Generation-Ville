#ifndef CITYCENTER_H
#define CITYCENTER_H
#include "../vector2d.h"

/**
 * @brief The CityCenter class, representing the active center of a city.
 */
class CityCenter
{
private :
    Vector2D center; /**< The location of the CityCenter */
    float influence; /**< The radius of the influence of the CityCenter */
public:
    CityCenter(const Vector2D& c, float infl);
    /**
     * @brief Getter of center
     * @return A copy of center
     */
    Vector2D getCenter() const;

    /**
     * @brief Getter of influence
     * @return influence
     */
    float getInfluence() const;

};


#endif // CITYCENTER_H
