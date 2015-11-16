#include "plan.h"
#include "MeshBuilder.h"

Plan::Plan(const Polyangle p) : poly(p)
{

}

void Plan::create(QList<Quartier> &qs, QList<Route> &rs)
{

    divide(poly, qs, rs);

    Mesh mf;

    for(int i = 0; i < qs.size(); ++i) {

        QList<Vector3D> geom;
        QList<int> topo;
        QList<Vector3D> norms;
        QString nom = "blop";
        Quartier quart = qs.at(i);
        const QVector<Vector2D> points = quart.getPoly().getLesPoints();

        if(points.size() == 4) {

            geom << points[0] << points[1] << points[2] << points[3];
            topo << 0 << 0 << 0
                 << 1 << 0 << 0
                 << 3 << 0 << 0

                 << 1 << 0 << 0
                 << 2 << 0 << 0
                 << 3 << 0 << 0;

            norms << Vector3D(0,0,1);
            Mesh tmp(geom, topo, norms, nom);

            mf.merge(tmp);
        }
        if(points.size() == 3){
            geom << points[0] << points[1] << points[2];
            topo << 0 << 0 << 0
                 << 2 << 0 << 0
                 << 1 << 0 << 0;
            norms << Vector3D(0,0,-1);
            Mesh tmp(geom, topo, norms, nom);
            mf.merge(tmp);
        }
    }
    MeshBuilder mb;
    QString str = "C:/Users/etu/Desktop/testTerrain.obj";
    mb.saveMesh(str, mf);

}

void Plan::divide(const Polyangle &p, QList<Quartier> &qs, QList<Route>& routes) const
{
    std::cout << "Poly : " << p.area() << std::endl;
    if(p.area() > 10000*10000-1){

        int cotes = p.getLesPoints().size();
        Polyangle p1, p2, pr;
        Droite d;

        if(cotes == 3) {
            //std::cout << "Par ici : tri " << std::endl;
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
                Vector2D elu23 = deux + dir23 * 0.3 + dir23 *0.4 * (rand()/RAND_MAX);
                Vector2D elu31 = trois + dir31 * 0.3 + dir31 *0.4 * (rand()/RAND_MAX);

                d = Droite(elu31, elu23-elu31);

            }
            if(l23 < l12 && l23 < l31) // segment 2-3 le plus petit
            {
                Vector2D dir12 = deux - un, dir31 = un-trois;
                Vector2D elu12 = un + dir12 * 0.3 + dir12 *0.4 * (rand()/RAND_MAX);
                Vector2D elu31 = trois + dir31 * 0.3 + dir31 *0.4 * (rand()/RAND_MAX);

                d = Droite(elu31, elu12-elu31);
            }
            if(l31 < l23 && l31 < l12) // segment 3-1 le plus petit
            {
                Vector2D dir23 = trois - deux, dir12 = deux-un;
                Vector2D elu12 = un + dir12 * 0.3 + dir12 *0.4 * (rand()/RAND_MAX);
                Vector2D elu23 = deux + dir23 * 0.3 + dir23 *0.4 * (rand()/RAND_MAX);

                d = Droite(elu12, elu23-elu12);
            }
        }
        if(cotes == 4) {

            /**

              Début construction quad coupé entre deux sommets opposés
              Résultat : deux tris

              */

            //std::cout << "Par ici : quad" << std::endl;
            Vector2D un, deux;
            un = p.getLesPoints().at(0);
            deux = p.getLesPoints().at(2);
            d = Droite(deux, un-deux);
        }

        std::cout << "Poly et droite " << p << std::endl << d.getO() << "," << d.getD() << std::endl;
        p.split(p1, p2, pr, d, 3.5);
        std::cout << "Route : " << pr << std::endl;

        std::cout << "Before divide p1 : " << p1 << std::endl;
        divide(p1, qs, routes);
        std::cout << "Before divide p2 : " << p2 << std::endl;
        divide(p2, qs, routes);
        routes.push_back(pr);
    }
    else {
        Quartier q(p, Quartier::RESIDENTIEL);
        //std::cout << "Quartier créé : " << p.getLesPoints().size() << std::endl;
        qs.push_back(q);
    }
}

