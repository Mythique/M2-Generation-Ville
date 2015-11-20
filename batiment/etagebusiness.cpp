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
        bats << std::make_pair(&eb,20);

        if(shrinkMax > 0 && aireMin < base.area())
        {
            bats << std::make_pair(&peb, 10); //10
            if(erer.getPoly1().area() > aireMin && erer.getPoly2().area() > aireMin)
            {
                bats << std::make_pair(&erer,5); //5
                bats << std::make_pair(&deb,10); //10
            }
            if(el.getPoly1().area() > aireMin && el.getPoly2().area() > aireMin && el.getPoly3().area() > aireMin)
            {
                bats << std::make_pair(&el,10); //5
            }
            if(del.getBase().area() > aireMin)
            {
                bats << std::make_pair(&del,10); //10
            }
        }
    }


    etageMesh.merge(Batiment::getRandomBatiment(bats)->generate());
    return etageMesh;

}

