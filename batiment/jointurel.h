#ifndef JOINTUREL_H
#define JOINTUREL_H
#include "batiment.h"

/**
 * @brief The JointureL class, representing a "L"-shaped storey that has been divided in three parts and joins back with bridges.
 */
class JointureL : public Batiment
{
private :
    Polyangle poly1; /**< The Polyangle of the first part of the "L" */
    Polyangle poly2; /**< The Polyangle of the second part of the "L" */
    Polyangle poly3; /**< The Polyangle of the third part of the "L" */

public:

    /**
     * @brief JointureL Constructor where the three Polyangles are given as parameters for the three parts of the JointureL
     * @param[in] p The Polyangle of the base
     * @param[in] h The height of the JointureL
     * @param[in] hE The height of the storey of the JointureL
     * @param[in] hm The maximal number of storeys after the JointureL
     * @param[in] sm The maximal number of shrinkages after the JointureL
     * @param[in] am The minimal area of the Division to allow further shrinkages
     * @param[in] p1 The Polyangle of the first part
     * @param[in] p2 The Polyangle of the second part
     * @param[in] p3 The Polyangle of the third part
     * @param[in] shrink If the three Polyangles have to be shrinked by a tenth of their size
     */
    JointureL(const Polyangle& p, float h, float hE, int hm, int sm, float am, const Polyangle& p1, const Polyangle& p2, const Polyangle& p3);
    JointureL(const Polyangle& p, float h, float hE, int hm, int sm, float am) : Batiment(p, h, hE, hm, sm, am) {}
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
     * @return A copy of poly3
     */
    Polyangle getPoly3() const;

    /**
     * @brief Setter of poly3
     * @param[in] value The new value of poly3
     */
    void setPoly3(const Polyangle& value);
};

#endif // JOINTUREL_H
