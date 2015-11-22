#ifndef REZDECHAUSSEEBUSINESS_H
#define REZDECHAUSSEEBUSINESS_H
#include "batiment.h"

/**
 * @brief The RezDeChausseeBusiness class, representing the first part to create a business building.
 */
class RezDeChausseeBusiness : public Batiment
{
public:

    /**
     * @brief RezDeChausseeBusiness
     * @param[in] p The Polyangle containing the shape of the RezDeChausseeBusiness.
     * @param[in] h The height of the base of the RezDeChausseeBusiness.
     * @param[in] hE The height of the storeys of the RezDeChausseeBusiness.
     * @param[in] hm The maximal number of storeys on the RezDeChausseeBusiness.
     * @param[in] sm The maximal number of shrinkages of the base.
     * @param[in] am The minimal area of the base to allow a shrinkage.
     */
    RezDeChausseeBusiness(const Polyangle& p, float h, float hE,int hm, int sm, float am) : Batiment(p, h, hE, hm, sm, am) {}
    Mesh generate() const;
};

#endif // REZDECHAUSSEEBUSINESS_H
