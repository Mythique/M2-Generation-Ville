#ifndef BATIMENT_H
#define BATIMENT_H
#include "generateur.h"
#include "polyangle.h"

class Batiment : public Generateur
{
protected :
    int hMax;
    int shrinkMax;
    float aireMin;
    Polyangle base;
    float hauteur, hauteurEtage;
public:
    Batiment();
    Batiment(const Polyangle& p, float h, float hE, int hM, int sM, float aM);
    Batiment(int hM, int sM, float aM);
    virtual Mesh generate() const =0 ;
    static Batiment* getRandomBatiment(QVector<std::pair<Batiment *, int> > bats);
};

#endif // BATIMENT_H
