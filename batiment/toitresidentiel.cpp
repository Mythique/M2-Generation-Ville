#include "toitresidentiel.h"
#include "toit.h"
#include "toitplat.h"
#include "toitbordure.h"

Mesh ToitResidentiel::generate() const
{
    QVector<std::pair<Batiment*,int>> bats;

    Toit toit(base, hauteur, hauteurEtage/2);
    ToitPlat toitPlat(base, hauteur, hauteurEtage/2);
    ToitBordure toitBordure(base, hauteur, hauteurEtage/2);

    bats << std::make_pair(&toit, 1);
    bats << std::make_pair(&toitPlat, 1);
    bats << std::make_pair(&toitBordure, 1);

    //Cheminee cheminee(base, hauteur, hauteurEtage / 2, hMax, shrinkMax, aireMin);
    Mesh toitMesh = Batiment::getRandomBatiment(bats)->generate();
    return toitMesh;
}
