#include "plan.h"
#include "MeshBuilder.h"
#include "../batiment/rezdechaussee.h"
#include "../mathutils.h"

Plan::Plan(const Polyangle& p, Mesh &mb, Mesh &mr, int i, QList<std::pair<Vector2D, int> > *pR, const CityCenter &cc) : poly(p), meshBatiments(mb), meshRoute(mr), id(i), pointsRoute(pR), cityCenter(cc) {}

void Plan::create(QList<Quartier> &qs, QList<Route> &rs)
{
    divide(poly, qs, rs);
}

bool Plan::getFirstPointBetween(const Vector2D& a, const Vector2D& b, float decalage, int& out) {

        Vector2D tmp = b - a;

        for(int i = 0; i < pointsRoute->size(); ++i) {
            if(pointsRoute->operator [](i).second != id) {

                Vector2D comp = pointsRoute->operator [](i).first - a;
                Vector2D tmpNorm = tmp.normalized();
                Vector2D compNorm = comp.normalized();

                if(std::abs(tmpNorm.x() - compNorm.x()) < 0.01 && std::abs(compNorm.y() - tmpNorm.y()) < 0.01) {
                    float dist = (a.distanceToPoint2DSquared(pointsRoute->operator [](i).first))/a.distanceToPoint2DSquared(b);
                    if(dist > decalage && dist < (1-decalage)){
                        out = i;
                        return true;
                    }
                }
            }
        }
        return false;
}

void Plan::divide(const Polyangle &p, QList<Quartier> &qs, QList<Route>& routes)
{
    Vector2D center(0,0);
    for(int i = 0; i < p.getLesPoints().size(); ++i) {
        center += p.getLesPoints()[i];
    }
    center /= p.getLesPoints().size();
    float influence = MathUtils::fonctionQuadratiqueInv(0.0, cityCenter.getInfluence(), center.distanceToPoint2D(cityCenter.getCenter()));
    float concentration = 1.2-(influence*0.4);

    float randArea = MathUtils::random(5000*concentration, 6500*concentration);

    if(p.area() > randArea){

        int cotes = p.getLesPoints().size();
        Polyangle p1, p2, pr;
        Droite d;

        if(cotes == 3) {
            double l12, l23, l31;

            Vector2D un, deux, trois;
            un = p.getLesPoints().at(0);
            deux = p.getLesPoints().at(1);
            trois = p.getLesPoints().at(2);

            l12 = un.distanceToPoint2DSquared(deux);
            l23 = deux.distanceToPoint2DSquared(trois);
            l31 = trois.distanceToPoint2DSquared(un);

            /**

              Début construction triangle coupé en deux: lien entre les deux côtés les plus longs
              Résultat : un quad et un tri

              */

            if(l12 < l23 && l12 < l31) // segment 1-2 le plus petit
            {
                Vector2D dir23 = trois - deux, dir31 = un-trois;
                Vector2D elu23;
                int indiceElu23;
                if(!getFirstPointBetween(deux,trois, 0.4, indiceElu23)) {
                    elu23 = deux + dir23 * 0.4 + dir23 *0.2 * (rand()/RAND_MAX);
                    pointsRoute->append(std::make_pair(elu23, id));
                }
                else {
                    elu23 = pointsRoute->at(indiceElu23).first;
                    pointsRoute->removeAt(indiceElu23);
                }
                Vector2D elu31;
                int indiceElu31;
                if(!getFirstPointBetween(trois, un, 0.4, indiceElu31)) {
                    elu31 = trois + dir31 * 0.4 + dir31 *0.2 * (rand()/RAND_MAX);
                    pointsRoute->append(std::make_pair(elu31, id));
                }
                else {
                    elu31 = pointsRoute->at(indiceElu31).first;
                    pointsRoute->removeAt(indiceElu31);
                }

                d = Droite(elu31, elu23-elu31);

            }
            else if(l23 < l12 && l23 < l31) // segment 2-3 le plus petit
            {
                Vector2D dir12 = deux - un, dir31 = un-trois;
                Vector2D elu12;
                int indiceElu12;
                if(!getFirstPointBetween(un, deux, 0.4, indiceElu12)) {
                    elu12 = un + dir12 * 0.4 + dir12 *0.2 * (rand()/RAND_MAX);
                    pointsRoute->append(std::make_pair(elu12, id));
                }
                else {
                    elu12 = pointsRoute->at(indiceElu12).first;
                    pointsRoute->removeAt(indiceElu12);
                }
                Vector2D elu31;
                int indiceElu31;
                if(!getFirstPointBetween(trois, un, 0.4, indiceElu31)) {
                    elu31 = trois + dir31 * 0.4 + dir31 *0.2 * (rand()/RAND_MAX);
                    pointsRoute->append(std::make_pair(elu31, id));
                }
                else {
                    elu31 = pointsRoute->at(indiceElu31).first;
                    pointsRoute->removeAt(indiceElu31);
                }

                d = Droite(elu31, elu12-elu31);
            }
            else //(l31 < l23 && l31 < l12) // segment 3-1 le plus petit
            {
                Vector2D dir23 = trois - deux, dir12 = deux-un;
                Vector2D elu12;
                int indiceElu12;
                if(!getFirstPointBetween(un, deux, 0.4, indiceElu12)) {
                    elu12 = un + dir12 * 0.4 + dir12 *0.2 * (rand()/RAND_MAX);
                    pointsRoute->append(std::make_pair(elu12, id));
                }
                else {
                    elu12 = pointsRoute->at(indiceElu12).first;
                    pointsRoute->removeAt(indiceElu12);
                }
                Vector2D elu23;
                int indiceElu23;
                if(!getFirstPointBetween(deux, trois, 0.4, indiceElu23)) {
                    elu23 = deux + dir23 * 0.4 + dir23 *0.2 * (rand()/RAND_MAX);
                    pointsRoute->append(std::make_pair(elu23, id));
                }
                else {
                    elu23 = pointsRoute->at(indiceElu23).first;
                    pointsRoute->removeAt(indiceElu23);
                }

                d = Droite(elu12, elu23-elu12);
            }
        }
        if(cotes == 4) {

            /**

              Début construction quad coupé entre deux côtés opposés
              Résultat : deux quad

             */


            double l12, l23, l34, l41;

            Vector2D un, deux, trois, quatre;
            un = p.getLesPoints().at(0);
            deux = p.getLesPoints().at(1);
            trois = p.getLesPoints().at(2);
            quatre = p.getLesPoints().at(3);

            l12 = un.distanceToPoint2DSquared(deux);
            l23 = deux.distanceToPoint2DSquared(trois);
            l34 = trois.distanceToPoint2DSquared(quatre);
            l41 = quatre.distanceToPoint2DSquared(un);


            double lc13 = l12 + l34, lc24 = l23 + l41;

            if(lc13 > lc24) {
                Vector2D dir12 = deux-un, dir34 = quatre-trois;
                Vector2D elu12;
                int indiceElu12;
                if(!getFirstPointBetween(un, deux, 0.35, indiceElu12)){
                    elu12 = un + dir12 * 0.35 + dir12 * 0.3 * (rand()/RAND_MAX);
                    pointsRoute->append(std::make_pair(elu12, id));
                }
                else {
                    elu12 = pointsRoute->at(indiceElu12).first;
                    pointsRoute->removeAt(indiceElu12);
                }
                Vector2D elu34;
                int indiceElu34;
                if(!getFirstPointBetween(trois, quatre, 0.35, indiceElu34)) {
                    elu34 = trois + dir34 * 0.35 + dir34 * 0.3 * (rand()/RAND_MAX);
                    pointsRoute->append(std::make_pair(elu34, id));
                }else {
                    elu34 = pointsRoute->at(indiceElu34).first;
                    pointsRoute->removeAt(indiceElu34);
                }

                d = Droite(elu12, elu34-elu12);
            }
            else {
                Vector2D dir23 = trois-deux, dir41 = un-quatre;
                Vector2D elu23;
                int indiceElu23;
                if(!getFirstPointBetween(deux,trois,0.35,indiceElu23)){
                    elu23 = deux + dir23 * 0.35 + dir23 * 0.3 * (rand()/RAND_MAX);
                    pointsRoute->append(std::make_pair(elu23, id));
                }
                else {
                    elu23 = pointsRoute->at(indiceElu23).first;
                    pointsRoute->removeAt(indiceElu23);
                }
                Vector2D elu41;
                int indiceElu41;
                if(!getFirstPointBetween(quatre,un,0.35,indiceElu41)){
                    elu41 = quatre + dir41 * 0.35 + dir41 * 0.3 * (rand()/RAND_MAX);
                    pointsRoute->append(std::make_pair(elu41, id));
                }
                else {
                    elu41 = pointsRoute->at(indiceElu41).first;
                    pointsRoute->removeAt(indiceElu41);
                }

                d = Droite(elu23, elu41-elu23);
            }

            /**

              Début construction quad coupé entre deux sommets opposés
              Résultat : deux tris

              */

            //std::cout << "Par ici : quad" << std::endl;
            /*Vector2D un, deux;
            un = p.getLesPoints().at(0);
            deux = p.getLesPoints().at(2);
            d = Droite(deux, un-deux);*/


        }

        p.split(p1, p2, pr, d, 3.5);
        divide(p1, qs, routes);
        divide(p2, qs, routes);
        Route rou(pr);
        rou.generate(meshRoute);
    }
    else {
        float petit = p.plusPetitCote();
        float tailleTrottoir = std::min(2.5,petit*0.5), tailleBatiment = std::min(15.0f, petit*0.3f);
        float rand = MathUtils::random(0,1);
        /*if(rand < influence*0.2) {*/
            Quartier q(p, tailleTrottoir, tailleBatiment, Quartier::TypeQuartier::GRATTECIEL);
            q.generate(meshBatiments, cityCenter);
        /*}
        else if(rand < influence*0.5) {
            Quartier q(p, tailleTrottoir, tailleBatiment, Quartier::TypeQuartier::MARCHAND);
            q.generate(meshBatiments, cityCenter);
        }
        else {
            Quartier q(p, tailleTrottoir, tailleBatiment, Quartier::TypeQuartier::RESIDENTIEL);
            q.generate(meshBatiments, cityCenter);
        }*/
        /*else {
            Quartier q(p, 0, 15*concentration, Quartier::TypeQuartier::CHAMPS);
            q.generate(meshBatiments, cityCenter);
        }*/
    }
}

Mesh Plan::getMeshRoute()
{
    return meshRoute;
}

CityCenter Plan::getCityCenter()
{
    return cityCenter;
}

Mesh Plan::getMeshBatiment()
{
    return meshBatiments;
}

