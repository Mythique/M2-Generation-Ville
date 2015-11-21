#ifndef TOITBORDURE_H
#define TOITBORDURE_H
#include "batiment.h"
#include "vector3d.h"
#include "polyangle.h"
#include "mesh.h"

/**
 * @brief The ToitBordure class, representing a flat roof with a border.
 */
class ToitBordure : public Batiment
{
private:
    Polyangle base; /**< The Polyangle of the base */
    float hauteur; /**< The height of the base of the ToitBordure */
    float hauteurToit; /**< The height of the ToitBordure */
public:
    ToitBordure();
    /**
     * @brief ToitBordure
     * @param[in] p The Polyangle of the base of the ToitBordure
     * @param[in] h The height of the base of the ToitBordure
     * @param[in] hToit The height of the ToitBordure
     */
    ToitBordure(const Polyangle& p, float h, float hToit) : base(p), hauteur(h), hauteurToit(hToit) {}
    Mesh generate() const;
};

#endif // TOITBORDURE_H
