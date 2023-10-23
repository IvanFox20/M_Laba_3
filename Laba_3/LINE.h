#include "Point.h"

class Line
{
public:
    Point p1; // ����� ������ �����
    Point p2; // ����� ����� �����
    double k, b; // k - �����������, b - �����
    bool operator==(const Line another); // �������� ��������� ���� �����
    bool operator!=(const Line another); // �������� ����������� ���� �����
    Line(); // ����������� �� ���������
    Line(Point P1, Point P2); // �����������, ����������� ��� �����
    Line(double coefficent, double slope); // �����������, ����������� ����������� � ���� ������� �����
    Line(Point P1, double coefficent); // �����������, ����������� ����� � �����������
    double Get_coiffecient(); // ����� ��������� ������������
    double Get_slope(); // ����� ��������� ���� ������� �����
    void Display(); // ����� ������ ���������� � ����� �� �����
};
