#include "toitresidentiel.h"
#include "toit.h"

Mesh ToitResidentiel::generate() const
{
    Toit t1(base,hauteur,hauteurEtage);
    return t1.generate();

}
