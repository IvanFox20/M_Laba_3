#pragma once
#include "Ellipse.h"
class Circle : public Ellipse //����� Circle ����������� �� ������ Ellipse
{
public:
	Circle();
	Circle(Point& center, double rad);
	~Circle();

	double radius() const; //������ �����
};
