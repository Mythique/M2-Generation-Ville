#ifndef BATIMENT_H
#define BATIMENT_H
#include "generateur.h"

class Batiment : public Generateur
{
private :
    int hMax;
    int shrinkMax;
    float aireMax;
public:
    Batiment();
    Batiment(int hM, int sM, float aM);
    virtual Mesh generate() const =0 ;
};

#endif // BATIMENT_H