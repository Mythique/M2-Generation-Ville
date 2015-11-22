#ifndef ETAGEBUSINESS_H
#define ETAGEBUSINESS_H
#include "batiment.h"
#include "batiment.h"
#include "vector3d.h"
#include "mesh.h"
#include "polyangle.h"

/**
 * @brief The EtageBusiness class, representing a storey of a business building.
 */
class EtageBusiness : public Batiment
{

public:
    /**
     * @brief EtageBusiness
     * @param[in] p The Polyangle containing the shape of the EtageBusiness.
     * @param[in] h The height of the base of the EtageBusiness.
     * @param[in] hE The height of the storeys of the EtageBusiness.
     * @param[in] hm The maximal number of storeys on the EtageBusiness.
     * @param[in] sm The maximal number of shrinkages of the base.
     * @param[in] am The minimal area of the base to allow a shrinkage.
     */
    EtageBusiness(const Polyangle& p, float h, float hE, int hm, int sm, float am) : Batiment(p, h, hE, hm, sm, am) {}
    Mesh generate() const;

};

#endif // ETAGEBUSINESS_H
