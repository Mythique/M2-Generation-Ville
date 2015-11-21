#ifndef TOITBUSINESS_H
#define TOITBUSINESS_H
#include "batiment.h"

/**
 * @brief The ToitBusiness class, representing the roof of a business building.
 */
class ToitBusiness : public Batiment
{
public:
    ToitBusiness(const Polyangle & p, float h, float hE, int hm, int sm, float am) : Batiment(p, h, hE, hm, sm, am) {}
    Mesh generate() const;
};
#endif // TOITBUSINESS_H
