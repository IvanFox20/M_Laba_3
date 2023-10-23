#pragma once
#include"Polygon.h"

class Rectangle :public Polygon
{
public:
	Rectangle() = default;
	Point center();
	pair<Line, Line>diagonals();
	Rectangle(Point& P1, Point& P3, double k);
	~Rectangle() = default;
};