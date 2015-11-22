#ifndef PETITETAGERESIDENTIEL_H
#define PETITETAGERESIDENTIEL_H
#include "batiment.h"

/**
 * @brief The PetitEtageResidentiel class, representing a smaller storey on a residential building.
 */
class PetitEtageResidentiel : public Batiment
{
public:

    /**
     * @brief PetitEtageResidentiel
     * @param[in] p The Polyangle containing the shape of the PetitEtageResidentiel.
     * @param[in] h The height of the base of the PetitEtageResidentiel.
     * @param[in] hE The height of the storeys of the PetitEtageResidentiel.
     * @param[in] hm The maximal number of storeys on the PetitEtageResidentiel.
     * @param[in] sm The maximal number of shrinkages of the base.
     * @param[in] am The minimal area of the base to allow a shrinkage.
     */
    PetitEtageResidentiel(const Polyangle & p, float h, float hE, int hm, int sm, float am) : Batiment(p, h, hE, hm, sm, am) {}
    Mesh generate() const;
};

#endif // PETITETAGERESIDENTIEL_H
