#include "doubletoit.h"
#include "toitbusiness.h"

Mesh DoubleToit::generate() const
{
    ToitBusiness tb1(poly[0],hauteur,hauteurEtage,hMax,shrinkMax,aireMin);
    Mesh m = tb1.generate();

    for(int i = 1; i < poly.size(); i++)
    {
        m.merge(ToitBusiness(poly[i],hauteur,hauteurEtage,hMax,shrinkMax,aireMin).generate());
    }

    return m;
}
