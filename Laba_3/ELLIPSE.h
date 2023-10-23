#pragma once
#include "Shape.h"

class Ellipse : public Shape
{
protected:
    Point A; //фокус
    Point B; //фокус
    double d; // сумма раст = 2a. 
    double a;// = d / 2;
    double c; //= dist(A, B) / 2; // пол раст 
    double b; //= sqrt(a * a - c * c);


public:
    Ellipse() = default;
    Ellipse(const Point& P1, const Point& P2, double D) : A(P1), B(P2), d(D), a(D / 2), c(dist(P1, P2) / 2), b(sqrt(a* a - c * c)) {} //сконструировать из двух точек и double (два фокуса и сумма рассто€ний от эллипса до них);
    virtual ~Ellipse() = default;
    Ellipse& operator=(const Ellipse& E);
    double perimetr() const; //периметр
    double area() const; //площадь
    Point center() const; // центр
    std::pair<Point, Point> focuses() const; //фокусы
    std::pair<Line, Line> directrices(); // директрисы
    double eccentricity(); // е
    bool containsPoint(const Point& P) const override; //точка внутри фигуры или нет
    void rotate(Point center, double angle); // поворот
    void reflex(Point center);  //отражение относительно точки
    void reflex(Line axis); // отражение относительно пр€мой
    void scale(Point center, const double& coefficient); //гомотети€ с коэффициентом и центром
    bool operator==(const Shape& another) const;
    bool operator!=(const Shape& another) const;
    bool isCongruentTo(const Shape& another) const override; // равенство в геом. смысле
    bool isSimilarTo(const Shape& another)const override; //подобие
};