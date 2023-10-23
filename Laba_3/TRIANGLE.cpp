#include "Triangle.h"

Circle Triangle::circumscribedCircle() //опис.
{
    Point A = polygon[0]; Point B = polygon[1]; Point C = polygon[2];
    Line AB(A, B); Line BC(B, C);  Line CA(C, A);
    Point Circumcenter((A.x * Sin2(CA, AB) + B.x * Sin2(AB, BC) + C.x * Sin2(CA, BC) /
        (Sin2(CA, AB) + Sin2(AB, BC) + Sin2(CA, BC))), ((A.y * Sin2(CA, AB)) + B.y * Sin2(AB, BC) + C.y * Sin2(CA, BC)) /
        (Sin2(CA, AB) + Sin2(AB, BC) + Sin2(CA, BC)));

    return Circle(Circumcenter, dist(Circumcenter, A));
}

// P(X, Y) = [(x1 sin 2A + x2 sin 2B + x3 sin 2C)/ 
// (sin 2A + sin 2B + sin 2C), (y1 sin 2A + y2 sin 2B + y3 sin 2C)/ (sin 2A + sin 2B + sin 2C)]

Circle Triangle::inscribedCircle() //впис.
{
    double rad = (2 * area()) / (dist(polygon[0], polygon[1]) + dist(polygon[1], polygon[2]) + dist(polygon[2], polygon[0]));
    Point Center = orthocenter();
    return Circle(Center, rad);
}

Point Triangle::orthocenter()
{
    Line FirstPerpendicular = perpendicular(Line(polygon[1], polygon[2]), polygon[0]);
    Line SecondPerpendicular = perpendicular(Line(polygon[2], polygon[0]), polygon[1]);
    return intersect(FirstPerpendicular, SecondPerpendicular);
}
// точка пересечений высот тругольника

Line Triangle::EulerLine()
{
    return Line(orthocenter(), centroid());
}
// ѕр€ма€ Ёйлера проходит через церез центр описанной окружности, ортоцентр, центроид

Circle Triangle::ninePointsCircle()
{
    Point EulerCenter((orthocenter() + circumscribedCircle().focuses().first) / 2);
    double EulerRadius = circumscribedCircle().radius() / 2;
    return Circle(EulerCenter, EulerRadius);
}

//÷ентр окружности дев€ти точек лежит на пр€мой Ёйлера, 
//точно в середине отрезка между ортоцентром и центром описанной окружности
// –адиус окружности дев€ти точек равен половине радиуса описанной окружности