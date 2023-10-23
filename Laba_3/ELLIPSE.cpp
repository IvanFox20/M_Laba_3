#include "Shape.h"
#include "Ellipse.h"


Ellipse& Ellipse::operator=(const Ellipse& E)
{
    A = E.A;
    B = E.B;
    d = E.d;
    return *this;
}

double Ellipse::perimetr() const // периметр
{
    return (4 * Pi * a * b + (a - b) * 2) / a + b; // примерный

}

double Ellipse::area() const // площадь
{
    return Pi * d * sqrt(d * d - dist(A, B) * dist(A, B)) / 4;
}

Point Ellipse::center() const // центр
{
    return (A + B) / 2;
}

std::pair<Point, Point> Ellipse::focuses() const //фокусы
{
    return { A, B };
}

std::pair<Line, Line> Ellipse::directrices() //директрисы
{
    double distance = dist(A, B);
    double D = d / (2 * eccentricity());
    double a = B.x - A.x;
    double b = B.y - A.y;
    double x1 = A.x + a * (D + distance / 2) / distance;
    double y1 = A.y + b * (D + distance / 2) / distance;
    double x2 = B.x - a * (D + distance / 2) / distance;
    double y2 = B.y - b * (D + distance / 2) / distance;
    Point p1(x1, y1);
    Point p2(x2, y2);
    x1 = x1 - b;
    x2 = x2 - b;
    y1 = y1 + a;
    y2 = y2 + a;
    Point p3(x1, y1);
    Point p4(x2, y2);
    return { Line(p1, p3), Line(p2, p4) };
}

double Ellipse::eccentricity() //е
{
    return dist(A, B) / d;
}

bool Ellipse::containsPoint(const Point& P) const //точка внутри фигуры или нет
{
    if (dist(A, P) + dist(B, P) > EPS + d)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void Ellipse::rotate(Point center, double angle) // поворот
{
    A = Rotate(center, A, angle);
    B = Rotate(center, B, angle);
}

void Ellipse::reflex(Point center) //отражение относительно точки
{
    A = Reflex(A, center);
    B = Reflex(B, center);
}

void Ellipse::reflex(Line axis) // отражение относительно прямой
{
    A = Reflex(A, axis);
    B = Reflex(B, axis);
}

void Ellipse::scale(Point center, const double& coefficient) //гомотетия с коэффициентом и центром
{
    A = Scale(center, A, coefficient);
    B = Scale(center, B, coefficient);
}

bool Ellipse::operator==(const Shape& another) const
{
    if (dynamic_cast<const Ellipse*>(&another) == nullptr)
    {
        return false;
    }
    const Ellipse& Another = dynamic_cast<const Ellipse&>(another);
    if (((A == Another.A && B == Another.B) || (B == Another.A && A == Another.B)) && d == Another.d)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Ellipse::operator!=(const Shape& another) const
{
    return !(*this == another);
}

bool Ellipse::isCongruentTo(const Shape& another) const //равенство в геом. смысле
{
    if (dynamic_cast<const Ellipse*>(&another) == nullptr)
    {
        return false;
    }
    const Ellipse& Another = dynamic_cast<const Ellipse&>(another);
    if (dist(A, B) == dist(Another.A, Another.B) && d == Another.d)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Ellipse::isSimilarTo(const Shape& another) const //подобие
{
    if (dynamic_cast<const Ellipse*>(&another) == nullptr)
    {
        return false;
    }
    const Ellipse& Another = dynamic_cast<const Ellipse&>(another);
    if (dist(A, B) == 0)
    {
        return true;
    }
    if (dist(A, B) * Another.d == dist(Another.A, Another.B) * d) // другого 
    {
        return true;
    }
    else
    {
        return false;
    }
}