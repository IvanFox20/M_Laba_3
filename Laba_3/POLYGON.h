#pragma once
#include "Shape.h"

class Polygon : public Shape
{
protected:
	size_t size_; // количество вершин 
	vector<Point> polygon; // вектор вершин
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
	bool isCongruentTo(const Shape& another) const override; // геометрическое равенство 
	bool isSimilarTo(const Shape& another) const override; // подобие


	bool containsPoint(const Point& point) const override; // внутри ли точка
	bool isConvex(); // выпуклость


	void rotate(Point center, double angle); // поворот
	void reflex(Point center); // отражение относительно точки
	void reflex(Line axis); // отражение относительно пр€мой
	void scale(Point center, const double& coefficient); // маштабирование

	void Display();

};