#ifndef PARCELLE_H
#define PARCELLE_H
#include "../generateur.h"
#include "../polyangle.h"
#include "../mesh.h"
#include "citycenter.h"

/**
 * @brief The Parcelle class, representing the smaller part of the division of a Plan.
 */
class Parcelle
{
public :
    enum TypeConstruction : int {HABITATION, JARDIN, BUSINESS, GRATTECIEL}; /**< Types of the different buildings that can be built on the Parcelle */
private:
    Polyangle poly; /**< The Polyangle representing the shape of the area of the Parcelle */
    TypeConstruction type; /**< The type of the Parcelle */
public:

    /**
     * @brief Parcelle
     * @param[in] p The Polyangle representing the shape of the area of the Parcelle
     * @param[in] t The type of the Parcelle
     */
    Parcelle(const Polyangle& p, TypeConstruction t) : poly(p), type(t){}

    /**
     * @brief generate Generate a Batiment, based on the type, and merges it in m
     * @param[inout] m The mesh to merge in
     * @param[in] cc The CityCenter to consider for the generation of the Batiment
     */
    void generate(Mesh& m, const CityCenter &cc);

    /**
     * @brief Getter of poly;
     * @return A copy of poly
     */
    Polyangle getPoly();
};

#endif // PARCELLE_H
