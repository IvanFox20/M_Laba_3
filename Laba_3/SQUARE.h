#pragma once
#include "Rectangle.h"
#include "Circle.h"
class Square : public Rectangle
{
public:
	Square() = default;
	Square(Point& P1, Point& P3); // P1 � P3 ������ ��������������� ���� ��������
	Circle circumscribedCircle(); //��������� ��������� ���������� ��������
	Circle inscribedCircle(); //��������� ��������� ���������� ��������
	~Square() = default;

};
