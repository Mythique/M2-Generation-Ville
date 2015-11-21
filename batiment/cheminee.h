#ifndef CHEMINEE_H
#define CHEMINEE_H
#include "batiment.h"
/**
 * @brief The Cheminee class, representing chimneys on the top of buildings.
 */
class Cheminee : public Batiment
{
public:
    Cheminee(const Polyangle & p, float h, float hE, int hm, int sm, float am) : Batiment(p, h, hE, hm, sm, am) {}
    Mesh generate() const;
};

#endif // CHEMINEE_H
