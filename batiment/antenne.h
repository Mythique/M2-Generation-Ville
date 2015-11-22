#ifndef ANTENNE_H
#define ANTENNE_H
#include "batiment.h"
/**
 * @brief The Antenne class, representing antennas on the top of buildings.
 */
class Antenne : public Batiment
{
public:
    /**
     * @brief Antenne
     * @param[in] p The Polyangle containing the shape of the Antenne.
     * @param[in] h The height of the base of the Antenne.
     * @param[in] hE The height of the storeys of the Antenne.
     * @param[in] hm The maximal number of storeys on the Antenne.
     * @param[in] sm The maximal number of shrinkages of the base.
     * @param[in] am The minimal area of the base to allow a shrinkage.
     */
    Antenne(const Polyangle & p, float h, float hE, int hm, int sm, float am) : Batiment(p, h, hE, hm, sm, am) {}
    Mesh generate() const;
};
#endif // ANTENNE_H
