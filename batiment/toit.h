#ifndef TOIT_H
#define TOIT_H
#include "batiment.h"
#include "vector3d.h"
#include "polyangle.h"
#include "mesh.h"

/**
 * @brief The Toit class, representing a standard roof.
 */
class Toit : public Batiment
{
private:
    Polyangle base; /**< The Polyangle of the base */
    float hauteur; /**< The height of the base of the Toit */
    float hauteurToit; /**< The height of the Toit */
public:
    Toit();
    /**
     * @brief Toit
     * @param[in] p The Polyangle of the base of the Toit
     * @param[in] h The height of the base of the Toit
     * @param[in] hToit The height of the Toit
     */
    Toit(const Polyangle& p, float h, float hToit) : base(p), hauteur(h), hauteurToit(hToit) {}
    Mesh generate() const;
};

#endif // TOIT_H
