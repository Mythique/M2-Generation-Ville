#include "route.h"
#include "../meshbuilder.h"
#include "../polyanglehauteur.h"
Route::Route(const Polyangle &q) : poly(q)
{

}

void Route::generate(Mesh& m)
{
    MeshBuilder mb;
    PolyangleHauteur ph(poly,-0.1);
    QVector<PolyangleHauteur> vect;
    vect<<ph;

    m.merge(mb.generationPolyanglesRelies(vect));
}
