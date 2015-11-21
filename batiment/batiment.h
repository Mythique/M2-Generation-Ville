#ifndef BATIMENT_H
#define BATIMENT_H
#include "generateur.h"
#include "polyangle.h"

/**
 * @brief The Batiment class. Inheriting classes are used for grammars building on Parcelles.
 */
class Batiment : public Generateur
{
protected :

    Polyangle base; /**< The shape of the Batiment on the ground. */
    float hauteur; /**< The height of the base of the Batiment. */
    float hauteurEtage; /**< The height of a storey. */
    int hMax; /**< The maximal number of storeys on the Batiment. */
    int shrinkMax; /**< The maximal number of shrinkages of the base. */
    float aireMin; /**< The minimal area of the base to allow a shrinkage. */
public:
    Batiment();
    /**
     * @brief Batiment
     * @param[in] p The Polyangle containing the shape of the Batiment.
     * @param[in] h The height of the base of the Batiment.
     * @param[in] hE The height of the storeys of the Batiment.
     * @param[in] hM The maximal number of storeys on the Batiment.
     * @param[in] sM The maximal number of shrinkages of the base.
     * @param[in] aM The minimal area of the base to allow a shrinkage.
     */
    Batiment(const Polyangle& p, float h, float hE, int hM, int sM, float aM);

    /**
     * @brief Generates a Mesh corresponding to the Batiment.
     * @return the Mesh of the Batiment.
     * @see getRandomBatiment()
     */
    virtual Mesh generate() const =0 ;

    /**
     * @brief Return a Batiment based on a vector containing pairs of Batiments and weights. The weight influences the chances for the Batiment to be chosen over the others.
     * @param[in] bats The vector containing pairs of Batiments and the associated weights.
     * @return The Batiment randomly chosen over the others.
     */
    static Batiment* getRandomBatiment(const QVector<std::pair<Batiment *, int>>& bats);

    /**
     * @brief Getter of hMax.
     * @return A copy of hMax.
     */
    int getHMax() const;

    /**
     * @brief Getter of shrinkMax.
     * @return A copy of shrinkMax;
     */
    int getShrinkMax() const;

    /**
     * @brief getAireMin
     * @return A copy of aireMin
     */
    float getAireMin() const;

    /**
     * @brief Getter of base.
     * @return A copy of base
     */
    Polyangle getBase() const;

    /**
     * @brief Getter of hauteur
     * @return A copy of hauteur
     */
    float getHauteur() const;

    /**
     * @brief Getter of hauteurEtage
     * @return A copy of hauteurEtage
     */
    float getHauteurEtage() const;
};

#endif // BATIMENT_H
