#include "Rectangle.h"
#include "Polygon.h"
Point Rectangle::center() // центр
{
    return (polygon[0] + polygon[2]) / 2;
}

pair<Line, Line> Rectangle::diagonals() // диаг.
{
    return { Line(polygon[0], polygon[2]), Line(polygon[1], polygon[3]) };
}

Rectangle::Rectangle(Point& P1, Point& P3, double k)
{
    if (k < 1)k = 1 / k;
    double tg2 = 2 * k;
    Point center = (P1 + P3) / 2;
    Point P2 = Rotate(center, P1, atan(tg2));
    Point P4 = Reflex(P2, center);
    polygon.push_back(P1);
    polygon.push_back(P2);
    polygon.push_back(P3);
    polygon.push_back(P4);
    size_ = 4;
}