#include "Shape.h"

double Shape::dist(const Point& P1, const Point& P2) const // +
{
    return sqrt((P1.x - P2.x) * (P1.x - P2.x) + (P1.y - P2.y) * (P1.y - P2.y));
}

bool Shape::onLine(const Line& L1, const Point& p) const // +
{
    if (p.x <= max(L1.p1.x, L1.p2.x)
        && p.x <= min(L1.p1.x, L1.p2.x)
        && (p.y <= max(L1.p1.y, L1.p2.y)
            && p.y <= min(L1.p1.y, L1.p2.y)))
        return true;

    return false;
}

int Shape::direction(const Point& a, const Point& b, const Point& c) const // +
{
    int val = (b.y - a.y) * (c.x - b.x)
        - (b.x - a.x) * (c.y - b.y);

    if (val == 0)

        // Коллинеарны
        return 0;

    else if (val < 0)

        // Направление против часовой стрелки
        return 2;

    // По часовой стрелке
    return 1;
}

bool Shape::isIntersect(const Line& l1, const Line& l2) const // +
{
    int dir1 = direction(l1.p1, l1.p2, l2.p1);
    int dir2 = direction(l1.p1, l1.p2, l2.p2);
    int dir3 = direction(l2.p1, l2.p2, l1.p1);
    int dir4 = direction(l2.p1, l2.p2, l1.p2);

    // При пересечении
    if (dir1 != dir2 && dir3 != dir4)
        return true;

    // Когда p2 линии 2 находится на линии 1
    if (dir1 == 0 && onLine(l1, l2.p1))
        return true;

    // Когда p1 линии 2 находится на линии 1
    if (dir2 == 0 && onLine(l1, l2.p2))
        return true;

    // Когда p2 линии 1 находятся на линии 2
    if (dir3 == 0 && onLine(l2, l1.p1))
        return true;

    // Когда p1 линии 1 находится на линии 2
    if (dir4 == 0 && onLine(l2, l1.p2))
        return true;

    return false;
}

bool Shape::equal(double& a, double& b) const
{
    return abs(a - b) < EPS;
}


Shape::~Shape()
{
}

Shape::Shape()
{
}
Point Shape::Scale(const Point center, const Point& P, const double& coefficient) const //масштаб.
{
    return center + (P - center) * coefficient;

}
Point Shape::Reflex(const Point& P, const Point& center) //симметри€
{
    return center * 2 - P;
}

Point Shape::Reflex(const Point& P, const Line& L) //симметри€
{
    Line line = perpendicular(L, P);
    Point center = intersect(line, L);
    return Reflex(P, center);
}

Point Shape::Rotate(const Point& center, const Point& P, const double angle) // поворот
{
    double x = P.x - center.x;
    double y = P.y - center.y;
    double fi = Pi * angle / 180;
    return center + Point(x * cos(fi) - y * sin(fi), x * sin(fi) + y * cos(fi));
}

Line Shape::perpendicular(const Line& L, const Point& P1)
{
    Point P2 = Point(P1.x + L.k, P1.y + (-1));
    return Line(P1, P2);
}
Point Shape::intersect(const Line& L1, const Line& L2) const //пересеч.
{
    double a = -L1.b * (-1) + L2.b * (-1);
    double b = -L1.k * L2.b + L2.k * L1.b;
    double det = Det(L1, L2);
    return Point(a / det, b / det);
}

double Shape::Det(const Line& L1, const Line& L2) const //определитель
{
    return L1.k * (-1) - (-1) * L2.k;
}
double Shape::Det(double a, double a1, double b, double b1) const
{
    return a * b1 - b * a1;
}
double Shape::cross_product(const Point P1, const Point P2) const // скал€р.
{
    return P2.y * P1.x - P2.x * P1.y;
}

double Shape::Sin(const Point P1, const Point P2) const
{

    return (P2.y * P1.x - P2.x * P1.y) / (sqrt(P1.x * P1.x + P1.y * P1.y) * sqrt(P2.x * P2.x + P2.y * P2.y));
}

double Shape::Sin(const Line L1, const Line L2) const
{
    return Sin(Point(-1, L1.k), Point(-1, L2.k));
}


double Shape::Cos(const Point P1, const Point P2) const
{
    return (P1.x * P2.x + P1.y * P2.y) / (sqrt(P1.x * P1.x + P1.y * P1.y) * sqrt(P2.x * P2.x + P2.y * P2.y));
}

double Shape::Cos(const Line L1, const Line L2) const
{
    return Cos(Point(-1, L1.k), Point(-1, L2.k));
}

double Shape::Sin2(const Line L1, const Line L2) const
{
    return 2 * Sin(L1, L2) * Cos(L1, L2);;
}