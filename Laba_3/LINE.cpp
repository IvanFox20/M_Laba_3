#include "Line.h"

// Оператор сравнения двух линий
bool Line::operator==(const Line another)
{
    if (another.k == this->k && another.b == this->b) {
        return true;
    }
    return false;
}

// Оператор неравенства двух линий
bool Line::operator!=(const Line another)
{
    return !(*this == another);
}

// Конструктор по умолчанию
Line::Line()
{
    k = 0;
    b = 0;
}

// Конструктор, принимающий две точки
Line::Line(Point P1, Point P2)
{
    this->p1 = P1;
    this->p2 = P2;
    this->k = (P2.y - P1.y) / (P2.x - P1.x);
    this->b = -k * P1.x + P1.y; // тк y - y1 = k(x - x1)
}

// Конструктор, принимающий коэффициент и угол наклона линии
Line::Line(double coefficent, double slope)
{
    this->k = coefficent;
    this->b = slope;
    this->p1 = Point(0, b); // просто две точки какие-то с x в нуле и в единице
    this->p2 = Point(1, k + b);
}

// Конструктор, принимающий точку и коэффициент
Line::Line(Point P1, double coefficent)
{
    this->p1 = P1;
    this->k = coefficent;
    this->b = -k * P1.x + P1.y; // тк y - y1 = k(x - x1)
    this->p2 = Point(P1.x + 1, k * (P1.x + 1) + b); // x просто подвинули на 1, а для y формула
}

// Метод получения коэффициента
double Line::Get_coiffecient()
{
    return k;
}

// Метод получения угла наклона линии
double Line::Get_slope()
{
    return b;
}

// Метод вывода информации о линии на экран
void Line::Display()
{
    if (k > 0) {
        if (b > 0) {
            cout << "y=" << k << "x" << "+" << b << endl;
        }
        else if (b == 0) {
            cout << "y=" << k << "x" << endl;
        }
        else {
            cout << "y=" << k << "x" << "-" << b << endl;
        }
    }
    if (k < 0) {
        if (b > 0) {
            cout << "y=" << "-" << k << "x" << "+" << b << endl;
        }
        else if (b == 0) {
            cout << "y=" << "-" << k << "x" << endl;
        }
        else {
            cout << "y=" << "-" << k << "x" << "-" << b << endl;
        }
    }
    else if (k == 0) {

        cout << "y=" << b << endl;

    }
}