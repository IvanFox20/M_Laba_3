#include "Line.h"

// �������� ��������� ���� �����
bool Line::operator==(const Line another)
{
    if (another.k == this->k && another.b == this->b) {
        return true;
    }
    return false;
}

// �������� ����������� ���� �����
bool Line::operator!=(const Line another)
{
    return !(*this == another);
}

// ����������� �� ���������
Line::Line()
{
    k = 0;
    b = 0;
}

// �����������, ����������� ��� �����
Line::Line(Point P1, Point P2)
{
    this->p1 = P1;
    this->p2 = P2;
    this->k = (P2.y - P1.y) / (P2.x - P1.x);
    this->b = -k * P1.x + P1.y; // �� y - y1 = k(x - x1)
}

// �����������, ����������� ����������� � ���� ������� �����
Line::Line(double coefficent, double slope)
{
    this->k = coefficent;
    this->b = slope;
    this->p1 = Point(0, b); // ������ ��� ����� �����-�� � x � ���� � � �������
    this->p2 = Point(1, k + b);
}

// �����������, ����������� ����� � �����������
Line::Line(Point P1, double coefficent)
{
    this->p1 = P1;
    this->k = coefficent;
    this->b = -k * P1.x + P1.y; // �� y - y1 = k(x - x1)
    this->p2 = Point(P1.x + 1, k * (P1.x + 1) + b); // x ������ ��������� �� 1, � ��� y �������
}

// ����� ��������� ������������
double Line::Get_coiffecient()
{
    return k;
}

// ����� ��������� ���� ������� �����
double Line::Get_slope()
{
    return b;
}

// ����� ������ ���������� � ����� �� �����
void Line::Display()
{
    if (k > 0) {
        if (b > 0) {
            cout << "y=" << k << "x" << "+" << b << endl;
        }
        else if (b == 0) {
            cout << "y=" << k << "x" << endl;
        }
        else {
            cout << "y=" << k << "x" << "-" << b << endl;
        }
    }
    if (k < 0) {
        if (b > 0) {
            cout << "y=" << "-" << k << "x" << "+" << b << endl;
        }
        else if (b == 0) {
            cout << "y=" << "-" << k << "x" << endl;
        }
        else {
            cout << "y=" << "-" << k << "x" << "-" << b << endl;
        }
    }
    else if (k == 0) {

        cout << "y=" << b << endl;

    }
}