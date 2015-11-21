#ifndef JOINTURE_H
#define JOINTURE_H
#include "batiment.h"

/**
 * @brief The Jointure class, representing a storey that has been divided and joins back with a bridge.
 */
class Jointure : public Batiment
{
private:
    Polyangle poly1; /**< The Polyangle of the first part of the Division that joins back */
    Polyangle poly2; /**< The Polyangle of the second part of the Division that joins back */
public:

    /**
     * @brief Jointure
     * @param[in] p The Polyangle of the base
     * @param[in] h The height of the Jointure
     * @param[in] hE The height of the storey of the Jointure
     * @param[in] hm The maximal number of storeys after the Jointure
     * @param[in] sm The maximal number of shrinkages after the Jointure
     * @param[in] am The minimal area of the Jointure to allow further shrinkages
     * @param[in] p1 The Polyangle of the first part
     * @param[in] p2 The Polyangle of the second part
     */
    Jointure(const Polyangle& p, float h, float hE, int hm, int sm, float am, const Polyangle& p1, const Polyangle& p2);
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

#endif // JOINTURE_H
