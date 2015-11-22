#ifndef PETITETAGEBUSINESS_H
#define PETITETAGEBUSINESS_H
#include "batiment.h"

/**
 * @brief The PetitEtageBusiness class, representing a smaller storey on a business building.
 */
class PetitEtageBusiness : public Batiment
{
public:

    /**
     * @brief PetitEtageBusiness
     * @param[in] p The Polyangle containing the shape of the PetitEtageBusiness.
     * @param[in] h The height of the base of the PetitEtageBusiness.
     * @param[in] hE The height of the storeys of the PetitEtageBusiness.
     * @param[in] hm The maximal number of storeys on the PetitEtageBusiness.
     * @param[in] sm The maximal number of shrinkages of the base.
     * @param[in] am The minimal area of the base to allow a shrinkage.
     */
    PetitEtageBusiness(const Polyangle& p, float h, float hE, int hm, int sm, float am) : Batiment(p, h, hE, hm, sm, am) {}
    Mesh generate() const;
};

#endif // PETITETAGEBUSINESS_H
