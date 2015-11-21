#ifndef MULTITOIT_H
#define MULTITOIT_H
#include "batiment.h"

/**
 * @brief The MultiToit class, representing the roof of a Batiment described by several Polyangles
 */
class MultiToit : public Batiment
{
private:
    QVector<Polyangle> poly; /**< A vector of Polyangles where to put the roofs */

public:
    /**
     * @brief MultiToit
     * @param[in] p The Polyangle of the base of the Batiment
     * @param[in] h The height of the base of the Batiment
     * @param[in] hE The height of the batiment
     * @param[in] hm The maximal number of storeys after the MultiToit
     * @param[in] sm The maximal number of shrinkages after the MultiToit
     * @param[in] am The minimal area to allow further shrinkages
     * @param[in] ps The vector containing the Polyangles where to put the roofs
     */
    MultiToit(const Polyangle& p, float h, float hE, int hm, int sm, float am, const QVector<Polyangle>& ps) : Batiment(p, h, hE, hm, sm, am), poly(ps) {}
    Mesh generate() const;

};
#endif // MULTITOIT_H
