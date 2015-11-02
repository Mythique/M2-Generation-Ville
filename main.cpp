#include <QCoreApplication>
#include "triangle.h"
#include "quadrangle.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Vector2D p1(0,0);
    Vector2D p2(10.26,-5.02);
    Vector2D p3(6.5,4.8);
    Vector2D p4(9.66,2.72);

    Triangle t(p1, p2, p3);
    std::cout << "aire triangle  : " <<  t.area() << std::endl;
    std::cout << "perimetre triangle  : " << t.perimetre() << std::endl;

    Quadrangle q(p1, p2, p3, p4);
    std::cout << "aire Quadrangle  : " <<  q.area() << std::endl;
    std::cout << "perimetre Quadrangle  : " << q.perimetre() << std::endl;

    return a.exec();
}

