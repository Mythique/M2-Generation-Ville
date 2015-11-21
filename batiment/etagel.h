#ifndef ETAGEL_H
#define ETAGEL_H
#include "batiment.h"

/**
 * @brief The EtageL class, representing a "L"-shaped storey with three parts.
 */
class EtageL : public Batiment
{
private:
    Polyangle poly1; /**< The Polyangle of the first part of the "L" */
    Polyangle poly2; /**< The Polyangle of the second part of the "L" */
    Polyangle poly3; /**< The Polyangle of the third part of the "L" */

public:
    /**
     * @brief EtageL Constructor where the three Polyangles are given as parameters for the three parts of the EtageL
     * @param[in] p The Polyangle of the base
     * @param[in] h The height of the EtageL
     * @param[in] hE The height of the storey of the EtageL
     * @param[in] hm The maximal number of storeys after the EtageL
     * @param[in] sm The maximal number of shrinkages after the EtageL
     * @param[in] am The minimal area of the Division to allow further shrinkages
     * @param[in] p1 The Polyangle of the first part
     * @param[in] p2 The Polyangle of the second part
     * @param[in] p3 The Polyangle of the third part
     * @param[in] shrink If the three Polyangles have to be shrinked by a tenth of their size
     */
    EtageL(const Polyangle& p, float h, float hE, int hm, int sm, float am, Polyangle p1, Polyangle p2, Polyangle p3) : Batiment(p, h, hE, hm, sm, am), poly1(p1), poly2(p2), poly3(p3) {}
    EtageL(const Polyangle& p, float h, float hE, int hm, int sm, float am);
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
#endif // ETAGEL_H
