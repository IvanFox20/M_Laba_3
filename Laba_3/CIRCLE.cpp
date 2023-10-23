#include "Circle.h"

Circle::Circle()
{
}

Circle::Circle(Point& center, double rad)
{
	A = center;
	B = center;
	a = rad;
	b = rad;
	d = 2 * rad;
	c = 0;

}

Circle::~Circle()
{
}

double Circle::radius() const
{
	return a;
}