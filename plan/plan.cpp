#include "plan.h"
#include "MeshBuilder.h"
#include "../batiment/rezdechaussee.h"
#include "../mathutils.h"

Plan::Plan(const Polyangle& p, Mesh &mb, Mesh &mr, int i, QList<std::pair<Vector2D, int> > *pR) : poly(p), meshBatiments(mb), meshRoute(mr), id(i), pointsRoute(pR) {}

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

                if(tmpNorm.x() == compNorm.x() && compNorm.y() == tmpNorm.y()) {
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

    if(p.area() > MathUtils::random(3000,5000)){

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

        //std::cout << "Poly et droite " << p << std::endl << d.getO() << "," << d.getD() << std::endl;
        p.split(p1, p2, pr, d, 3.5);
        //std::cout << "Route : " << pr << std::endl;

        //std::cout << "Before divide p1 : " << p1 << std::endl;
        divide(p1, qs, routes);
        //std::cout << "Before divide p2 : " << p2 << std::endl;
        divide(p2, qs, routes);
        //routes.push_back(pr);
        Route rou(pr);
        rou.generate(meshRoute);
    }
    else {
        Quartier q(p, 2.5, 10);
        q.generate(meshBatiments);
    }
}

Mesh Plan::getMeshRoute()
{
    return meshRoute;
}

Mesh Plan::getMeshBatiment()
{
    return meshBatiments;
}

