#ifndef TOITBUSINESS_H
#define TOITBUSINESS_H
#include "batiment.h"
class ToitBusiness:public Batiment
{
public:
    ToitBusiness(int hm,int sm,float am):Batiment(hm,sm,am){}
    Mesh generate() const;
};
#endif // TOITBUSINESS_H
