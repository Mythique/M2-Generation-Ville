#include "etagebusiness.h"
#include <iostream>
#include "mathutils.h"
#include "toit.h"
#include "toitplat.h"
#include "polyanglehauteur.h"
#include "meshbuilder.h"
#include "etage.h"
#include "doubleetagebusiness.h"
#include "toitbusiness.h"
#include "petitetagebusiness.h"
#include "division.h"
#include "etagel.h"
#include "divisionl.h"

Mesh EtageBusiness::generate() const
{
    MeshBuilder mb;
    Mesh etageMesh = mb.generationEtage(this);

    QVector<std::pair<Batiment*,int>> bats;

    EtageBusiness eb(base,hauteur+hauteurEtage,hauteurEtage,hMax-1,shrinkMax,aireMin);
    ToitBusiness tb(base,hauteur+hauteurEtage,hauteurEtage,hMax-1,shrinkMax,aireMin);
    PetitEtageBusiness peb(base,hauteur+hauteurEtage,hauteurEtage,hMax-1,shrinkMax-1,aireMin);
    DoubleEtageBusiness erer(base,hauteur+hauteurEtage,hauteurEtage,hMax-1,shrinkMax-1,aireMin);
    Division deb(base,hauteur+hauteurEtage,hauteurEtage,hMax-1,shrinkMax-1,aireMin);
    EtageL el(base,hauteur+hauteurEtage,hauteurEtage,hMax-1,shrinkMax-1,aireMin);
    DivisionL del(base,hauteur+hauteurEtage,hauteurEtage,hMax-1,shrinkMax-1,aireMin);

    bats << std::make_pair(&tb,2);
    if(hMax>1)
    {
        bats << std::make_pair(&eb,70);

        if(shrinkMax > 0 && aireMin < base.area() && base.plusPetitCote() > 5)
        {
            bats << std::make_pair(&peb, 10);
            if(erer.getPoly1().area() > aireMin && erer.getPoly2().area() > aireMin)
            {
                bats << std::make_pair(&erer,5);
                bats << std::make_pair(&deb,20);
            }
            if(el.getBase().area() > aireMin)
            {
                bats << std::make_pair(&el,5);
            }
            if(del.getBase().area() > aireMin)
            {
                bats << std::make_pair(&del,10);
            }
        }
    }


    etageMesh.merge(Batiment::getRandomBatiment(bats)->generate());
    return etageMesh;

}

