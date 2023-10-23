#pragma once
#include "Point.h"
#include "Line.h"

class Shape
{
public:
    Shape(); // Конструктор по умолчанию
    constexpr static const double EPS = 0.01; // Эпсилон - точность сравнения вещественных чисел
    virtual bool operator==(const Shape& another) const = 0; // Оператор сравнения двух фигур
    virtual bool operator!=(const Shape& another) const = 0; // Оператор неравенства двух фигур
    virtual bool isCongruentTo(const Shape& another) const = 0; // Метод проверки на геометрическую сходственность двух фигур
    virtual bool isSimilarTo(const Shape& another) const = 0; // Метод проверки на геометрическое подобие двух фигур
    virtual bool containsPoint(const Point& point) const = 0; // Метод проверки, содержится ли точка внутри фигуры
    virtual void rotate(Point center, double angle) = 0; // Метод поворота фигуры на заданный угол относительно заданной точки
    virtual void reflex(Point center) = 0; // Метод симметрии фигуры относительно заданной точки
    virtual void reflex(Line axis) = 0; // Метод симметрии фигуры относительно заданной оси
    virtual void scale(Point center, const double& coefficient) = 0; // Метод масштабирования фигуры относительно заданной точки с заданным коэффициентом
    virtual double area() const = 0; // Метод вычисления площади фигуры
    virtual double perimetr() const = 0; // Метод вычисления периметра фигуры
    Point Scale(const Point center, const Point& P, const double& coefficient) const; // Вспомогательный метод масштабирования точки относительно заданной точки с заданным коэффициентом
    Point Reflex(const Point& P, const Point& center); // Вспомогательный метод симметрии точки относительно заданной точки
    Point Reflex(const Point& P, const Line& L); // Вспомогательный метод симметрии точки относительно заданной оси
    Point Rotate(const Point& center, const Point& P, const double angle); // Вспомогательный метод поворота точки на заданный угол относительно заданной точки
    Line perpendicular(const Line& L, const Point& P1); // Вспомогательный метод нахождения перпендикуляра к заданной линии, проходящего через заданную точку
    Point intersect(const Line& L1, const Line& L2) const; // Вспомогательный метод нахождения точки пересечения двух линий
    double Det(const Line& L1, const Line& L2) const; // Вспомогательный метод вычисления определителя матрицы 2x2
    double Det(double a, double a1, double b, double b1) const; // Вспомогательный метод вычисления определителя матрицы 2x2
    double cross_product(const Point P1, const Point P2) const; // Вспомогательный метод вычисления векторного произведения двух векторов
    double Sin(const Point P1, const Point P2) const; //    Вспомогательный метод вычисления синуса угла между двумя векторами
    double Sin(const Line L1, const Line L2) const; // Вспомогательный метод вычисления синуса угла между двумя линиями
    double Cos(const Point P1, const Point P2) const; // Вспомогательный метод вычисления косинуса угла между двумя векторами
    double Cos(const Line L1, const Line L2) const; // Вспомогательный метод вычисления косинуса угла между двумя линиями
    double Sin2(const Line L1, const Line L2) const; // Вспомогательный метод вычисления квадрата синуса угла между двумя линиями
    double dist(const Point& P1, const Point& P2) const; // Вспомогательный метод вычисления расстояния между двумя точками
    bool onLine(const Line& L1, const Point& p) const; // Вспомогательный метод проверки, лежит ли точка на заданной линии
    int direction(const Point& a, const Point& b, const Point& c) const; // Вспомогательный метод определения направления поворота трех точек
    bool isIntersect(const Line& l1, const Line& l2) const; //Вспомогательный метод проверки, пересекаются ли две заданные линии
    bool equal(double& a, double& b) const; // Вспомогательный метод проверки, равны ли два вещественных числа с заданной точностью

    ~Shape(); // Деструктор по умолчанию
};