#ifndef TOITPLAT_H
#define TOITPLAT_H
#include "batiment.h"
#include "vector3d.h"
#include "polyangle.h"
#include "mesh.h"

/**
 * @brief The ToitPlat class, representing a raising roof with a flat part.
 */
class ToitPlat : public Batiment
{
private:
    Polyangle base; /**< The Polyangle of the base of the ToitPlat */
    float hauteur; /**< The height of the base of the ToitPlat */
    float hauteurToit; /**< The height of the ToitPlat */
public:
    ToitPlat();
    /**
     * @brief ToitPlat
     * @param[in] p The Polyangle of the base of the ToitPlat
     * @param[in] h The height of the base of the ToitPlat
     * @param[in] hToit The height of the ToitPlat
     */
    ToitPlat(Polyangle p, float h, float hToit) : base(p), hauteur(h), hauteurToit(hToit) {}
    Mesh generate() const;
};

#endif // TOITPLAT_H
