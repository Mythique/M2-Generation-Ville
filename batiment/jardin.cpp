#include "jardin.h"
#include "../mathutils.h"
#include "../meshbuilder.h"


Mesh Jardin::generate() const
{
    Mesh parc;
    int nb = 0;
    int shrinks = 0;
    Polyangle reduc = poly.shrink(1.5);
    while(reduc.plusPetitCote() > 3) {
        for(int i = 0; i < reduc.getLesPoints().size(); ++i) {
            Vector2D a = reduc.getLesPoints()[i];
            Vector2D b = reduc.getLesPoints()[(i+1)%reduc.getLesPoints().size()];
            Vector2D dir = b - a;

            float rand = MathUtils::random(0,1);
            Vector3D tronc = a + rand*dir;
            float randTronc = MathUtils::random(0.2,0.5);
            tronc.setZ(randTronc);
            MeshBuilder mb;
            float randH = MathUtils::random(4,10);
            float randR = MathUtils::random(0.8, 1.2);
            Mesh arbre = mb.generationCone(tronc, randH, 6, randR);
            parc.merge(arbre);
            ++nb;
        }
        float randShrink = MathUtils::random(1.8,2.2);
        reduc = reduc.shrink(randShrink);
        ++shrinks;
    }
    return parc;
}
