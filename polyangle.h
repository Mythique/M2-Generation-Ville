#ifndef POLYANGLE_H
#define POLYANGLE_H
#include <QVector>
#include "vector2d.h"
#include "mathutils.h"
#include "droite.h"

class Polyangle
{
protected:
    QVector<Vector2D> lesPoints;

public:
    Polyangle();
    Polyangle(const Polyangle &poly);
    Polyangle(QVector<Vector2D> points);
    double area() const;
    double perimetre() const ;
    Polyangle shrink(const double l) const;
    void uncross();

    bool split(Polyangle & p1, Polyangle & p2, Polyangle & route, const Droite & d, const double largeurDemiRoute) const;
    bool split(Polyangle & p1, Polyangle & p2, const Droite & d) const;

    void checkSens();
    std::pair<int, int> getHighestPair() const;

    float plusPetitCote() const;

    QVector<Vector2D> getLesPoints() const;
    void setLesPoints(const QVector<Vector2D> &value);
};
inline std::ostream& operator<<(std::ostream& out, const Polyangle& p){
    for (int i=0 ;i<p.getLesPoints().size();++i){
        out<<p.getLesPoints().at(i)<<" / ";
    }
      return out;
}
#endif // POLYANGLE_H
