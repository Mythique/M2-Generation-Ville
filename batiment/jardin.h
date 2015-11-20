#ifndef JARDIN_H
#define JARDIN_H
#include "../generateur.h"
#include "../polyangle.h"

class Jardin:public Generateur
{
private:
    Polyangle poly;
public:
Jardin(const Polyangle & p):poly(p){}
virtual Mesh generate() const;
};


#endif // JARDIN_H
