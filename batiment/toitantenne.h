#ifndef TOITANTENNE_H
#define TOITANTENNE_H
#include "batiment.h"
#include "vector3d.h"
#include "polyangle.h"
#include "mesh.h"

/**
 * @brief The ToitAntenne class, representing a roof that can have an antenna
 */
class ToitAntenne : public Batiment
{
private:
    Polyangle base; /**< The Polyangle of the base of the ToitAntenne */
    float hauteur; /**< The height of the base of the ToitAntenne */
    float hauteurToit; /**< The height of the ToitAntenne */
    float hauteurAntenne; /**< The height of the antenna */
public:
    ToitAntenne();
    /**
     * @brief ToitAntenne
     * @param[in] p The Polyangle of the base of the ToitAntenne
     * @param[in] h The height of the base of the ToitAntenne
     * @param[in] hToit The height of the ToitAntenne
     * @param[in] hAntenne The height of the antenna
     */
    ToitAntenne(const Polyangle& p, float h, float hToit, float hAntenne) : base(p), hauteur(h), hauteurToit(hToit), hauteurAntenne(hAntenne) {}
    Mesh generate() const;
};

#endif // TOITANTENNE_H
