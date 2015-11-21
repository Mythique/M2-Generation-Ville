#ifndef ROUTE_H
#define ROUTE_H
#include "../polyangle.h"
#include "../generateur.h"

/**
 * @brief The Route class, representing the separation between Quartiers.
 */
class Route
{
private:
    Polyangle poly; /**< The Polyangle representing the shape of the Route */
public:
    /**
     * @brief Route
     * @param[in] q The Polyangle representing the shape of the Route
     */
    Route(const Polyangle& q);

    /**
     * @brief Getter of poly
     * @return A copy of poly
     */
    Polyangle getQuad();

    /**
     * @brief generate Merges the Route's Mesh into m
     * @param[inout] m The Mesh to merge in
     */
    void generate(Mesh& m);


};

#endif // ROUTE_H
