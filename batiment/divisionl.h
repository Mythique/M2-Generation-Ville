#ifndef DIVISIOBL_H
#define DIVISIOBL_H
#include "batiment.h"

/**
 * @brief The DivisionL class, representing a "L"-shaped building that has been divided in three parts
 */
class DivisionL : public Batiment
{
private:
    Polyangle poly1; /**< The Polyangle of the base of the first part */
    Polyangle poly2; /**< The Polyangle of the base of the second part */
    Polyangle poly3; /**< The Polyangle of the base of the third part */

public:
    /**
     * @brief DivisionL Constructor where the two Polyangles are given as parameters for the two parts of the Division
     * @param[in] p The Polyangle of the base
     * @param[in] h The height of the DivisionL
     * @param[in] hE The height of the storey of the DivisionL
     * @param[in] hm The maximal number of storeys after the DivisionL
     * @param[in] sm The maximal number of shrinkages after the DivisionL
     * @param[in] am The minimal area of the Division to allow further shrinkages
     * @param[in] p1 The Polyangle of the first part
     * @param[in] p2 The Polyangle of the second part
     * @param[in] p3 The Polyangle of the third part
     * @param[in] shrink If the three Polyangles have to be shrinked by a tenth of their size
     * @see Polyangle::shrink
     */
    DivisionL(const Polyangle& p, float h, float hE, int hm, int sm, float am, const Polyangle& p1, const Polyangle& p2, const Polyangle& p3, bool shrink = true);
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

    /**
     * @brief Getter of poly3
     * @return[in] A copy of poly3
     */
    Polyangle getPoly3() const;

    /**
     * @brief Setter of poly3
     * @param[in] value The new value of poly3
     */
    void setPoly3(const Polyangle& value);
};

#endif // DIVISIOBL_H
