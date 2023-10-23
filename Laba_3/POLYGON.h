#pragma once
#include "Shape.h"

class Polygon : public Shape
{
protected:
	size_t size_; // ���������� ������ 
	vector<Point> polygon; // ������ ������
public:
	Polygon() {
		size_ = 0;
	};
	Polygon(const vector<Point>& g) : size_(g.size()), polygon(g) {}
	Polygon& operator=(const Polygon& P);

	double perimetr() const;
	double area() const;

	Point Next(size_t pos) const;
	Point Prev(size_t pos) const;
	size_t verticesCount() const;
	vector<Point> getVertices() const;
	Point centroid() const;

	bool operator==(const Shape& another) const;
	bool operator!=(const Shape& another) const;
	bool isCongruentTo(const Shape& another) const override; // �������������� ��������� 
	bool isSimilarTo(const Shape& another) const override; // �������


	bool containsPoint(const Point& point) const override; // ������ �� �����
	bool isConvex(); // ����������


	void rotate(Point center, double angle); // �������
	void reflex(Point center); // ��������� ������������ �����
	void reflex(Line axis); // ��������� ������������ ������
	void scale(Point center, const double& coefficient); // ��������������

	void Display();

};