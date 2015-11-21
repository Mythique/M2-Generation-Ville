#ifndef DOUBLEETAGEBUSINESS_H
#define DOUBLEETAGEBUSINESS_H
#include "batiment.h"
#include "vector3d.h"
#include "mesh.h"
#include "polyangle.h"

/**
 * @brief The DoubleEtageBusiness class, representing a storey of a business building divided in two.
 */
class DoubleEtageBusiness : public Batiment
{
private:
    Polyangle poly1; /**< The Polyangle of the base of the first part*/
    Polyangle poly2; /**< The Polyangle of the base of the second part */

public:
    DoubleEtageBusiness(const Polyangle& p, float h, float hE, int hm, int sm, float am);
    Mesh generate() const;

    /**
     * @brief Getter of poly1
     * @return A copy of poly1
     */
    Polyangle getPoly1() const;

    /**
     * @brief Setter of poly1
     * @param[in] value The new value of poly1
     */
    void setPoly1(const Polyangle& value);

    /**
     * @brief Getter of poly2
     * @return A copy of poly2
     */
    Polyangle getPoly2() const;

    /**
     * @brief Setter of poly2
     * @param[in] value The new value of poly2
     */
    void setPoly2(const Polyangle& value);
};

#endif // DOUBLEETAGEBUSINESS_H
