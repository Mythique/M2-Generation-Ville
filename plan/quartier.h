#ifndef QUARTIER_H
#define QUARTIER_H
#include <QList>
#include "../polyangle.h"
#include "../mesh.h"
#include "parcelle.h"
#include "citycenter.h"

/**
 * @brief The Quartier class, representing a final space that can be divided into several Parcelles.
 */
class Quartier
{
public :
    enum TypeQuartier : int {RESIDENTIEL, MARCHAND, GRATTECIEL, CHAMPS}; /**< The types of Quartier that can be created */
private:
    Polyangle poly; /**< The Polyangle representing the area of the Quartier */
    TypeQuartier type; /**< The type of the Quartier */
    QList<Parcelle> parcelles; /**< The list of Parcelles that are created from the Quartier */
public:

    Quartier();

    /**
     * @brief Quartier
     * @param[in] polya The Polyangle representing the area of the Quartier
     * @param[in] tailleTrottoir The size of the pavement around the Quartier
     * @param[in] tailleBatiment The depth of the Parcelles in the Quartier
     * @param[in] tq The type of the Quartier
     */
    Quartier(const Polyangle& polya, double tailleTrottoir, double tailleBatiment, const TypeQuartier tq);

    /**
     * @brief generate Generates the different Parcelles in the Quartier after they are created.
     * @param[inout] mesh The Mesh to merge in
     * @param[in] cc The CityCenter to consider
     */
    void generate(Mesh& mesh, const CityCenter& cc);

    /**
     * @brief Getter of poly
     * @return A copy of poly
     */
    const Polyangle getPoly();
};

#endif // QUARTIER_H
