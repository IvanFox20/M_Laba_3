#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#define Pi  3.1415926535

using namespace std;

struct Point {
public:
    double x, y;

    Point()
    {
        x = 0;
        y = 0;
    }

    Point(double _x, double _y)
    {
        Init(_x, _y);
    }

    void Init(double _x, double _y)
    {
        x = _x;
        y = _y;
    }

    double get_x()
    {
        return x;
    }

    double get_y()
    {
        return y;
    }

    void Display()
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }

    Point operator=(Point pnt)
    {
        (*this).x = pnt.x;
        (*this).y = pnt.y;
        return (*this);
    }

    friend bool operator ==(const Point& a, const Point& b) { return a.x == b.x && a.y == b.y; }
    friend bool operator !=(const Point& a, const Point& b) { return !(a == b); }

    Point& operator+=(const Point& P)
    {
        x += P.x;
        y += P.y;
        return *this;
    }
    Point& operator-=(const Point& P)
    {
        x -= P.x;
        y -= P.y;
        return *this;
    }
    Point operator/(const double k)  const
    {
        return Point(x / k, y / k);
    }
    Point operator*(const double k) const
    {
        return Point(x * k, y * k);
    }
    Point operator+(const Point& P2) const
    {
        Point tmp = *this;
        return (tmp += P2);
    }
    Point operator-() const {
        return Point(-x, -y);
    }
    Point operator-(const Point& P2) const
    {
        Point tmp = *this;
        return (tmp += -P2);
    }
};