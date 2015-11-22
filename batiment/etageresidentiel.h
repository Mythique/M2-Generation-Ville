#ifndef ETAGERESIDENTIEL_H
#define ETAGERESIDENTIEL_H
#include "batiment.h"

/**
 * @brief The EtageResidentiel class, representing a storey on a residential building.
 */
class EtageResidentiel : public Batiment
{
public:
    /**
     * @brief EtageResidentiel
     * @param[in] p The Polyangle containing the shape of the EtageResidentiel.
     * @param[in] h The height of the base of the EtageResidentiel.
     * @param[in] hE The height of the storeys of the EtageResidentiel.
     * @param[in] hm The maximal number of storeys on the EtageResidentiel.
     * @param[in] sm The maximal number of shrinkages of the base.
     * @param[in] am The minimal area of the base to allow a shrinkage.
     */
    EtageResidentiel(const Polyangle& p, float h, float hE, int hm, int sm, float am) : Batiment(p, h, hE, hm, sm, am) {}
    Mesh generate() const;
};


#endif // ETAGERESIDENTIEL_H
