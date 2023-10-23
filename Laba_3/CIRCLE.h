#pragma once
#include "Ellipse.h"
class Circle : public Ellipse //Класс Circle наследуется от класса Ellipse
{
public:
	Circle();
	Circle(Point& center, double rad);
	~Circle();

	double radius() const; //радиус круга
};
