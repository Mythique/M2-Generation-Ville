#ifndef REZDECHAUSSEEBUSINESS_H
#define REZDECHAUSSEEBUSINESS_H
#include "batiment.h"

/**
 * @brief The RezDeChausseeBusiness class, representing the first part to create a business building.
 */
class RezDeChausseeBusiness : public Batiment
{
public:
    RezDeChausseeBusiness(const Polyangle& p, float h, float hE,int hm, int sm, float am) : Batiment(p, h, hE, hm, sm, am) {}
    Mesh generate() const;
};

#endif // REZDECHAUSSEEBUSINESS_H
