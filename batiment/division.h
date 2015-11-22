#ifndef DIVISION_H
#define DIVISION_H
#include "batiment.h"
/**
 * @brief The Division class, representing a Batiment that has been divided in two parts that are built in parallel.
 */
class Division : public Batiment
{
private :
    Polyangle poly1; /**< The Polyangle of the base of the first part */
    Polyangle poly2; /**< The Polyangle of the base of the second part */
public:

    /**
     * @brief Division
     * @param[in] p The Polyangle containing the shape of the Division.
     * @param[in] h The height of the base of the Division.
     * @param[in] hE The height of the storeys of the Division.
     * @param[in] hm The maximal number of storeys on the Division.
     * @param[in] sm The maximal number of shrinkages of the base.
     * @param[in] am The minimal area of the base to allow a shrinkage.
     */
    Division(const Polyangle& p, float h, float hE, int hm, int sm, float am);

    /**
     * @brief Division Constructor where the two Polyangles are given as parameters for the two parts of the Division
     * @param[in] p The Polyangle of the base
     * @param[in] h The height of the Division
     * @param[in] hE The height of the storey of the Division
     * @param[in] hm The maximal number of storeys after the Division
     * @param[in] sm The maximal number of shrinkages after the Division
     * @param[in] am The minimal area of the Division to allow further shrinkages
     * @param[in] p1 The Polyangle of the first part
     * @param[in] p2 The Polyangle of the second part
     */
    Division(const Polyangle& p, float h, float hE, int hm, int sm, float am, const Polyangle& p1, const Polyangle & p2) : Batiment(p,h, hE, hm, sm, am), poly1(p1), poly2(p2) {}
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

#endif // DIVISION_H
