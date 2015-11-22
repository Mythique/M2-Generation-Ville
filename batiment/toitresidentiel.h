#ifndef TOITRESIDENTIEL_H
#define TOITRESIDENTIEL_H
#include "batiment.h"

/**
 * @brief The ToitResidentiel class, representing the roof of a residential building.
 */
class ToitResidentiel : public Batiment
{
public:
    /**
     * @brief ToitResidentiel
     * @param[in] p The Polyangle containing the shape of the ToitResidentiel.
     * @param[in] h The height of the base of the ToitResidentiel.
     * @param[in] hE The height of the storeys of the ToitResidentiel.
     * @param[in] hm The maximal number of storeys on the ToitResidentiel.
     * @param[in] sm The maximal number of shrinkages of the base.
     * @param[in] am The minimal area of the base to allow a shrinkage.
     */
    ToitResidentiel(const Polyangle& p, float h, float hE, int hm, int sm, float am) : Batiment(p, h, hE, hm, sm, am) {}
    Mesh generate() const;
};

#endif // TOITRESIDENTIEL_H
