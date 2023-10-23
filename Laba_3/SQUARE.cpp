#include "Square.h"

Square::Square(Point& P1, Point& P3)
{
    double tg = 2;
    Point center = (P1 + P3) / 2;
    Point P2 = Rotate(center, P1, atan(tg));
    Point P4 = Reflex(P2, center);
    polygon.push_back(P1);
    polygon.push_back(P2);
    polygon.push_back(P3);
    polygon.push_back(P4);
    size_ = 4;
}

Circle Square::circumscribedCircle() //опис.
{
    Point p = Point((polygon[0] + polygon[2]) / 2);
    return Circle(p, dist(p, polygon[0]));
}

Circle Square::inscribedCircle() // впис.
{
    Point p = Point((polygon[0] + polygon[2]) / 2);
    return Circle(p, dist(polygon[0], polygon[1]) / 2);
}