#pragma once
#include "Point.h"
#include "Line.h"

class Shape
{
public:
    Shape(); // ����������� �� ���������
    constexpr static const double EPS = 0.01; // ������� - �������� ��������� ������������ �����
    virtual bool operator==(const Shape& another) const = 0; // �������� ��������� ���� �����
    virtual bool operator!=(const Shape& another) const = 0; // �������� ����������� ���� �����
    virtual bool isCongruentTo(const Shape& another) const = 0; // ����� �������� �� �������������� �������������� ���� �����
    virtual bool isSimilarTo(const Shape& another) const = 0; // ����� �������� �� �������������� ������� ���� �����
    virtual bool containsPoint(const Point& point) const = 0; // ����� ��������, ���������� �� ����� ������ ������
    virtual void rotate(Point center, double angle) = 0; // ����� �������� ������ �� �������� ���� ������������ �������� �����
    virtual void reflex(Point center) = 0; // ����� ��������� ������ ������������ �������� �����
    virtual void reflex(Line axis) = 0; // ����� ��������� ������ ������������ �������� ���
    virtual void scale(Point center, const double& coefficient) = 0; // ����� ��������������� ������ ������������ �������� ����� � �������� �������������
    virtual double area() const = 0; // ����� ���������� ������� ������
    virtual double perimetr() const = 0; // ����� ���������� ��������� ������
    Point Scale(const Point center, const Point& P, const double& coefficient) const; // ��������������� ����� ��������������� ����� ������������ �������� ����� � �������� �������������
    Point Reflex(const Point& P, const Point& center); // ��������������� ����� ��������� ����� ������������ �������� �����
    Point Reflex(const Point& P, const Line& L); // ��������������� ����� ��������� ����� ������������ �������� ���
    Point Rotate(const Point& center, const Point& P, const double angle); // ��������������� ����� �������� ����� �� �������� ���� ������������ �������� �����
    Line perpendicular(const Line& L, const Point& P1); // ��������������� ����� ���������� �������������� � �������� �����, ����������� ����� �������� �����
    Point intersect(const Line& L1, const Line& L2) const; // ��������������� ����� ���������� ����� ����������� ���� �����
    double Det(const Line& L1, const Line& L2) const; // ��������������� ����� ���������� ������������ ������� 2x2
    double Det(double a, double a1, double b, double b1) const; // ��������������� ����� ���������� ������������ ������� 2x2
    double cross_product(const Point P1, const Point P2) const; // ��������������� ����� ���������� ���������� ������������ ���� ��������
    double Sin(const Point P1, const Point P2) const; //    ��������������� ����� ���������� ������ ���� ����� ����� ���������
    double Sin(const Line L1, const Line L2) const; // ��������������� ����� ���������� ������ ���� ����� ����� �������
    double Cos(const Point P1, const Point P2) const; // ��������������� ����� ���������� �������� ���� ����� ����� ���������
    double Cos(const Line L1, const Line L2) const; // ��������������� ����� ���������� �������� ���� ����� ����� �������
    double Sin2(const Line L1, const Line L2) const; // ��������������� ����� ���������� �������� ������ ���� ����� ����� �������
    double dist(const Point& P1, const Point& P2) const; // ��������������� ����� ���������� ���������� ����� ����� �������
    bool onLine(const Line& L1, const Point& p) const; // ��������������� ����� ��������, ����� �� ����� �� �������� �����
    int direction(const Point& a, const Point& b, const Point& c) const; // ��������������� ����� ����������� ����������� �������� ���� �����
    bool isIntersect(const Line& l1, const Line& l2) const; //��������������� ����� ��������, ������������ �� ��� �������� �����
    bool equal(double& a, double& b) const; // ��������������� ����� ��������, ����� �� ��� ������������ ����� � �������� ���������

    ~Shape(); // ���������� �� ���������
};