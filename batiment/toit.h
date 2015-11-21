#ifndef TOIT_H
#define TOIT_H
#include "batiment.h"
#include "vector3d.h"
#include "polyangle.h"
#include "mesh.h"

/**
 * @brief The Toit class, deprecated
 */
class Toit : public Batiment
{
private:
    Polyangle base;
    float hauteur, hauteurToit;
public:
    Toit();
    Toit(Polyangle p, float h, float hToit) : base(p), hauteur(h), hauteurToit(hToit) {}
    Mesh generate() const;
};

#endif // TOIT_H
