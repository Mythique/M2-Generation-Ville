#include "doubletoit.h"
#include "toitbusiness.h"

Mesh DoubleToit::generate() const
{
    ToitBusiness tb1(poly1,hauteur,hauteurEtage,hMax,shrinkMax,aireMin);
    ToitBusiness tb2(poly2,hauteur,hauteurEtage,hMax,shrinkMax,aireMin);

    Mesh m=tb1.generate();
    m.merge(tb2.generate());
    return m;
}
