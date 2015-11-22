#ifndef REZDECHAUSSERESIDENTIEL_H
#define REZDECHAUSSERESIDENTIEL_H
#include "batiment.h"

/**
 * @brief The RezDeChausseeResidentiel class, representing the first part to create a residential building.
 */
class RezDeChausseeResidentiel : public Batiment
{
public:

    /**
     * @brief RezDeChausseeResidentiel
     * @param[in] p The Polyangle containing the shape of the RezDeChausseeResidentiel.
     * @param[in] h The height of the base of the RezDeChausseeResidentiel.
     * @param[in] hE The height of the storeys of the RezDeChausseeResidentiel.
     * @param[in] hm The maximal number of storeys on the RezDeChausseeResidentiel.
     * @param[in] sm The maximal number of shrinkages of the base.
     * @param[in] am The minimal area of the base to allow a shrinkage.
     */
    RezDeChausseeResidentiel(const Polyangle& p, float h, float hE, int hm, int sm, float am) : Batiment(p, h, hE, hm, sm, am) {}
    Mesh generate() const;
};

#endif // REZDECHAUSSERESIDENTIEL_H
