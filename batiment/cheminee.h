#ifndef CHEMINEE_H
#define CHEMINEE_H
#include "batiment.h"
/**
 * @brief The Cheminee class, representing chimneys on the top of buildings.
 */
class Cheminee : public Batiment
{
public:
    /**
     * @brief Cheminee
     * @param[in] p The Polyangle containing the shape of the Cheminee.
     * @param[in] h The height of the base of the Cheminee.
     * @param[in] hE The height of the storeys of the Cheminee.
     * @param[in] hm The maximal number of storeys on the Cheminee.
     * @param[in] sm The maximal number of shrinkages of the base.
     * @param[in] am The minimal area of the base to allow a shrinkage.
     */
    Cheminee(const Polyangle & p, float h, float hE, int hm, int sm, float am) : Batiment(p, h, hE, hm, sm, am) {}
    Mesh generate() const;
};

#endif // CHEMINEE_H
