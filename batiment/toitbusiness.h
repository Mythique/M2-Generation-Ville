#ifndef TOITBUSINESS_H
#define TOITBUSINESS_H
#include "batiment.h"

/**
 * @brief The ToitBusiness class, representing the roof of a business building.
 */
class ToitBusiness : public Batiment
{
public:
    /**
     * @brief ToitBusiness
     * @param[in] p The Polyangle containing the shape of the ToitBusiness.
     * @param[in] h The height of the base of the ToitBusiness.
     * @param[in] hE The height of the storeys of the ToitBusiness.
     * @param[in] hm The maximal number of storeys on the ToitBusiness.
     * @param[in] sm The maximal number of shrinkages of the base.
     * @param[in] am The minimal area of the base to allow a shrinkage.
     */
    ToitBusiness(const Polyangle & p, float h, float hE, int hm, int sm, float am) : Batiment(p, h, hE, hm, sm, am) {}
    Mesh generate() const;
};
#endif // TOITBUSINESS_H
