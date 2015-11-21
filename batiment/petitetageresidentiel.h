#ifndef PETITETAGERESIDENTIEL_H
#define PETITETAGERESIDENTIEL_H
#include "batiment.h"

/**
 * @brief The PetitEtageResidentiel class, representing a smaller storey on a residential building.
 */
class PetitEtageResidentiel : public Batiment
{
public:

    PetitEtageResidentiel(const Polyangle & p, float h, float hE, int hm, int sm, float am) : Batiment(p, h, hE, hm, sm, am) {}
    Mesh generate() const;
};

#endif // PETITETAGERESIDENTIEL_H
