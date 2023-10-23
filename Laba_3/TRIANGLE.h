#pragma once
#include "Polygon.h"
#include "Circle.h"

class Triangle : public Polygon
{
public:
	Triangle(vector<Point>& g)
	{
		this->size_ = g.size();
		this->polygon = g;
	}
	Circle circumscribedCircle(); //вычисл€ет описанную окружность треугольника
	Circle inscribedCircle(); //вычисл€ет вписанную окружность треугольника
	Point orthocenter(); //вычисл€ет ортоцентр треугольника
	Line EulerLine(); //вычисл€ет пр€мую Ёйлера треугольника
	Circle ninePointsCircle(); //вычисл€ет окружность дев€ти точек треугольника
};