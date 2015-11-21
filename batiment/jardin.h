#ifndef JARDIN_H
#define JARDIN_H
#include "../generateur.h"
#include "../polyangle.h"

/**
 * @brief The Jardin class, representing a garden filled with pines.
 */
class Jardin : public Generateur
{
private:
    Polyangle poly; /**< The Polyangle of the surface */
public:
    /**
     * @brief Jardin
     * @param[in] p The Polyangle of the surface
     */
    Jardin(const Polyangle& p) : poly(p) {}

    /**
     * @brief Generates cones representing pines, along several shrinkages of poly.
     * @return A Mesh containing all the cones.
     */
    virtual Mesh generate() const;
};


#endif // JARDIN_H
