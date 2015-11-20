#include "toitbusiness.h"
#include "toitplat.h"
#include "toitbordure.h"
#include "toitantenne.h"

Mesh ToitBusiness::generate() const
{
    QVector<std::pair<Batiment*,int>> bats;

    ToitPlat toitPlat(base, hauteur, hauteurEtage/2);
    ToitBordure toitBordure(base, hauteur, hauteurEtage/3);
    ToitAntenne toitAntenne(base, hauteur, hauteurEtage/3, hauteurEtage * 3);

    bats << std::make_pair(&toitPlat, 1)
         << std::make_pair(&toitBordure, 1)
         << std::make_pair(&toitAntenne, 2);

    Mesh toitMesh = Batiment::getRandomBatiment(bats)->generate();
    return toitMesh;
}
