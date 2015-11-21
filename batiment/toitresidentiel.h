#ifndef TOITRESIDENTIEL_H
#define TOITRESIDENTIEL_H
#include "batiment.h"

/**
 * @brief The ToitResidentiel class, representing the roof of a residential building.
 */
class ToitResidentiel : public Batiment
{
public:
    ToitResidentiel(const Polyangle& p, float h, float hE, int hm, int sm, float am) : Batiment(p, h, hE, hm, sm, am) {}
    Mesh generate() const;
};

#endif // TOITRESIDENTIEL_H
