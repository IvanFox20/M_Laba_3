#pragma once
#include "Shape.h"

class Ellipse : public Shape
{
protected:
    Point A; //�����
    Point B; //�����
    double d; // ����� ���� = 2a. 
    double a;// = d / 2;
    double c; //= dist(A, B) / 2; // ��� ���� 
    double b; //= sqrt(a * a - c * c);


public:
    Ellipse() = default;
    Ellipse(const Point& P1, const Point& P2, double D) : A(P1), B(P2), d(D), a(D / 2), c(dist(P1, P2) / 2), b(sqrt(a* a - c * c)) {} //��������������� �� ���� ����� � double (��� ������ � ����� ��������� �� ������� �� ���);
    virtual ~Ellipse() = default;
    Ellipse& operator=(const Ellipse& E);
    double perimetr() const; //��������
    double area() const; //�������
    Point center() const; // �����
    std::pair<Point, Point> focuses() const; //������
    std::pair<Line, Line> directrices(); // ����������
    double eccentricity(); // �
    bool containsPoint(const Point& P) const override; //����� ������ ������ ��� ���
    void rotate(Point center, double angle); // �������
    void reflex(Point center);  //��������� ������������ �����
    void reflex(Line axis); // ��������� ������������ ������
    void scale(Point center, const double& coefficient); //�������� � ������������� � �������
    bool operator==(const Shape& another) const;
    bool operator!=(const Shape& another) const;
    bool isCongruentTo(const Shape& another) const override; // ��������� � ����. ������
    bool isSimilarTo(const Shape& another)const override; //�������
};