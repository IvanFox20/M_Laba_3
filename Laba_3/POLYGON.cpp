#include "Polygon.h"

Polygon& Polygon::operator=(const Polygon& P)
{
    size_ = P.size_;
    for (size_t i = 0; i < size_; ++i)
    {
        polygon[i] = P.polygon[i];
    }
    return *this;
}

double Polygon::perimetr() const
{
    double Perimeter = 0;
    for (size_t i = 0; i < size_; ++i)
    {
        Perimeter += dist(Prev(i), polygon[i]);
    }
    return Perimeter;
}

double Polygon::area() const
{
    double s = 0;
    for (size_t i = 0; i < size_; ++i)
    {
        s += Det(polygon[i].x, polygon[i].y, Next(i).x, Next(i).y);
    }
    return 0.5 * abs(s);
}

Point Polygon::Next(size_t pos) const // след. точка
{
    return polygon[(pos + 1) % size_];
}

Point Polygon::Prev(size_t pos) const // пред. точка
{
    return  polygon[(pos - 1 + size_) % size_];
}

Point Polygon::centroid() const
{
    double x = 0;
    double y = 0;
    for (size_t i = 0; i < size_; ++i)
    {
        x += polygon[i].x;
        y += polygon[i].y;
    }
    return Point(x / size_, y / size_);
}

size_t Polygon::verticesCount() const // колво вершин
{
    return size_t();
}

vector<Point> Polygon::getVertices() const //вектор точек полигонов
{
    return vector<Point>();
}

bool Polygon::operator==(const Shape& another) const
{
    if (dynamic_cast<const Polygon*>(&another) == nullptr)
        return false;
    const Polygon& Another = dynamic_cast<const Polygon&>(another);
    if (size_ != Another.size_ || this->polygon != Another.polygon)
        return false;
    else
        return true;
}

bool Polygon::operator!=(const Shape& another) const
{
    return !(*this == another);
}

bool Polygon::isCongruentTo(const Shape& another) const // подобие в геом. смысле
{
    if (*this == another)
        return true;

    if (dynamic_cast<const Polygon*>(&another) == nullptr)
    {
        return false;
    }

    const Polygon& Another = dynamic_cast<const Polygon&>(another);
    if (size_ != Another.size_)
    {
        return false;
    }
    if (!isSimilarTo(another))
    {
        return false;
    }
    bool check = true;
    for (size_t i = 0; i < size_; ++i)
    {
        for (size_t j = 0; j < size_; ++j)
        {
            if (dist(polygon[i], Next(i)) != dist(Another.polygon[i], Another.Next(i)))
            {
                check = false; break;
            }
        }
        if (check == true)
        {
            break;
        }
    }
    return check;
}

bool Polygon::isSimilarTo(const Shape& another) const // подобие
{
    if (*this == another) return true;
    if (dynamic_cast<const Polygon*>(&another) == nullptr)
        return false;
    const Polygon& Another = dynamic_cast<const Polygon&>(another);
    if (size_ != Another.size_)
        return false;
    double k = perimetr() / Another.perimetr();
    bool check = true;
    for (size_t i = 0; i < size_; ++i)
    {
        for (size_t j = 0; j < size_; ++j)
        {
            if (dist(polygon[i], Next(i)) / dist(Another.polygon[i], Another.Next(i)) != k)
            {
                check = false; break;
            }
        }
        if (check == true)
        {
            break;
        }
    }
    if (!check)
        return check;

    for (size_t i = 0; i < size_; ++i)
    {
        double a = abs(Sin(Line(polygon[i], Next(i)), Line(polygon[i], Prev(i))));
        for (size_t j = 0; j < size_; ++j)
        {

            double b = abs(Sin(Line(Another.polygon[j], Another.Next(j)), Line(Another.polygon[j], Another.Prev(j))));
            if (!equal(a, b))
            {
                cout << endl << a << endl;
                cout << endl << b << endl;
                check = false; break;
            }
        }
        if (check == true)
        {
            break;
        }
    }

    return check;

}


bool Polygon::containsPoint(const Point& point) const // точка внутри или нет
{
    if (size_ < 3)
        return false;
    // Ћини€, котора€ уходит от точки на бесконечность
    Line exline = { point, { 9999, point.y } };
    int count = 0;
    int i = 0;
    do
    {
        Line side = { polygon[i], Next(i) };
        if (isIntersect(side, exline))
        {
            if (direction(side.p1, point, side.p2) == 0)
                return onLine(side, point);
            count++;
        }
        i = (i + 1) % size_;
    } while (i != 0);

    // когда количество пересечений нечетно
    return count & 1;
}

void Polygon::rotate(Point center, double angle) // поворот 
{
    for (size_t i = 0; i < size_; ++i) {
        polygon[i] = Rotate(center, polygon[i], angle);
    }
}

void Polygon::reflex(Point center) // симметри€ отн. точки
{
    for (size_t i = 0; i < size_; ++i) {
        polygon[i] = Reflex(polygon[i], center);
    }
}

void Polygon::reflex(Line axis) // отн. пр€мой
{
    for (size_t i = 0; i < size_; ++i) {
        polygon[i] = Reflex(polygon[i], axis);
    }
}

void Polygon::scale(Point center, const double& coefficient)
{
    for (size_t i = 0; i < size_; ++i) {
        polygon[i] = Scale(center, polygon[i], coefficient);
    }
}

void Polygon::Display()
{
    for (size_t i = 0; i < size_; ++i)
    {
        polygon[i].Display();
    }
}

bool Polygon::isConvex() //вып. или нет
{
    double check = 0;
    for (size_t i = 0; i < size_; ++i) {
        double new_check = cross_product(Next(i) - polygon[i], Prev(i) - polygon[i]);
        if (check * new_check < 0) {
            return false;
        }
        check = new_check;
    }
    return true;
}