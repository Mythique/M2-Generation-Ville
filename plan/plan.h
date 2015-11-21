#ifndef PLAN_H
#define PLAN_H
#include <QList>
#include "../polyangle.h"
#include "route.h"
#include "quartier.h"
#include "citycenter.h"

/**
 * @brief The Plan class, representing the space to divide into Quatiers, Routes and Parcelles
 */
class Plan
{
private:
    Polyangle poly; /**< The Polyangle representing the space to divide */
    Mesh meshBatiments; /**< The Mesh to merge the Batiments in */
    Mesh meshRoute; /**< The Mesh to merge the Routes in */
    int id; /**< The id of the Plan, used to make a Route continue another if possible. Must be unique. */
    QList<std::pair<Vector2D, int>>* pointsRoute; /**< A list containing pairs of Routes' extremities and the id of the Plan the Route is created in */
    CityCenter cityCenter; /**< The city center to consider for the Plan */

    /**
     * @brief divide Divides a Polyangle into three parts : two Polyangles and a Route. The division is based on the number of faces of the Polyangle and goes on until the area is too small.
     * @param[in] p The Polyangle to divide.
     * @see create()
     */
    void divide(const Polyangle& p);

    /**
     * @brief getFirstPointBetween Finds a point that can be used as a starting point to make a Route, based on pointsRoute.
     * @param[in] a The first position of the side to check
     * @param[in] b The second position of the side to check
     * @param[in] decalage The offset, in percentage, from the vertices of the side where the point can't be chosen
     * @param[out] out The chosen starting point of the Route
     * @return True if a starting point has been found, false else.
     */
    bool getFirstPointBetween(const Vector2D& a, const Vector2D& b, float decalage, int &out);
public:
    /**
     * @brief Plan
     * @param[in] p The Polyangle representing the space to divide
     * @param[in] mb The Mesh to merge the Batiments in
     * @param[in] mr The Mesh to merge the Routes in
     * @param[in] i The id of the Plan. Must be unique.
     * @param[in] pR The list containing pairs of Route's extremities and the id of the Plan the Route is created in
     * @param[in] cc The city center to consider
     */
    Plan(const Polyangle& p, Mesh& mb, Mesh& mr, int i, QList<std::pair<Vector2D, int>>* pR, const CityCenter& cc);

    /**
     * @brief create The begining of the division of the Plan.
     * @see divide()
     */
    void create();

    /**
     * @brief Getter of meshBatiments
     * @return A copy of meshBatiments
     */
    Mesh getMeshBatiment();

    /**
     * @brief Getter of meshRoute
     * @return A copy of meshRoute
     */
    Mesh getMeshRoute();

    /**
     * @brief Getter of cityCenter;
     * @return A copy of cityCenter
     */
    CityCenter getCityCenter();

};

#endif // PLAN_H
