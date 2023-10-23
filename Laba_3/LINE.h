#include "Point.h"

class Line
{
public:
    Point p1; // Точка начала линии
    Point p2; // Точка конца линии
    double k, b; // k - коэффициент, b - сдвиг
    bool operator==(const Line another); // Оператор сравнения двух линий
    bool operator!=(const Line another); // Оператор неравенства двух линий
    Line(); // Конструктор по умолчанию
    Line(Point P1, Point P2); // Конструктор, принимающий две точки
    Line(double coefficent, double slope); // Конструктор, принимающий коэффициент и угол наклона линии
    Line(Point P1, double coefficent); // Конструктор, принимающий точку и коэффициент
    double Get_coiffecient(); // Метод получения коэффициента
    double Get_slope(); // Метод получения угла наклона линии
    void Display(); // Метод вывода информации о линии на экран
};
