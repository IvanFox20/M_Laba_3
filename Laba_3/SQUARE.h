#pragma once
#include "Rectangle.h"
#include "Circle.h"
class Square : public Rectangle
{
public:
	Square() = default;
	Square(Point& P1, Point& P3); // P1 и P3 задают противоположные углы квадрата
	Circle circumscribedCircle(); //вычисляет описанную окружность квадрата
	Circle inscribedCircle(); //вычисляет вписанную окружность квадрата
	~Square() = default;

};
