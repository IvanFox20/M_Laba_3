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
	Circle circumscribedCircle(); //��������� ��������� ���������� ������������
	Circle inscribedCircle(); //��������� ��������� ���������� ������������
	Point orthocenter(); //��������� ��������� ������������
	Line EulerLine(); //��������� ������ ������ ������������
	Circle ninePointsCircle(); //��������� ���������� ������ ����� ������������
};