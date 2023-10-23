#include "Square.h"
#include "Triangle.h"
#include "Polygon.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "Circle.h"

int main()
{

    vector<Shape*> A;
    vector<Point> g = { Point(0,0), Point(4,7), Point(8, 0) };
    Triangle M(g);
    vector<Point> w = { Point(2,1), Point(1,2), Point(1,3), Point(2,4), Point(2,3), Point(2,2) };
    Polygon R(w);
    Point K(7, 0);
    Circle C(K, 0.62);
    A.push_back(&M);
    A.push_back(&R);
    A.push_back(&C);
    for (int i = 0; i < 3; i++) {
        cout << A[i]->area() << endl;
    }
    ////triangle
    // 
    /*vector<Point> g = { Point(0,0), Point(4,7), Point(8, 0)};
    Triangle M(g);
    Triangle K(g);
    K.rotate(Point(6, 0), 90);
    if (M.isSimilarTo(K))
    {
        cout << "SIMILAR" << endl;
    }
    if (M.isCongruentTo(K))
    {
        cout << "CONGRUENT" << endl;
    }*/

    //polygon
    // 
   /* vector<Point> g = { Point(2,1), Point(1,2), Point(1,3), Point(2,4), Point(2,3), Point(2,2)};
    Polygon M(g);
    M.Display();
    cout << endl;
    Polygon K(g);
    K.rotate(Point(2,4), 90);
    K.Display();
    cout << endl;
    if (M.isSimilarTo(K))
   {
       cout << "SIMILAR" << endl;
   }
   if (M.isCongruentTo(K))
   {
       cout << "CONGRUENT" << endl;
   }*/

   //triangle and circle
   // 
   /*vector<Point> g = { Point(6, 0), Point(7, 2), Point(8, 0) };
   Triangle M(g);
   Point K(7, 0);
   Circle C(K, 0.62);
   double rad_tr = M.circumscribedCircle().radius();
   if (C.radius() == rad_tr)
   {
       cout << "True" << endl;
   }
   else cout << "False" << endl;

   Circle C1(K, 0.75);
   double rad_tr1 = M.inscribedCircle().radius();
   if (C1.radius() == rad_tr1)
   {
       cout << "True" << endl;
   }
   else cout << "False" << endl;*/



   ///* if (M.containsPoint(Point(7, 1)))
   // {
   //     cout << "Yes" << endl;
   // }
   // else cout << "No" << endl;
   // if (M.containsPoint(Point(7, 3)))
   // {
   //     cout << "Yes" << endl;
   // }
   // else cout << "No" << endl;
   // cout << endl;*/
   // 
   // vector<Point> l = { Point(2,4), Point(2,6), Point(4,6), Point(4,4) };
   // Polygon B(l);
   // B.Display();
   // cout << endl;
   // /*Polygon A(l);
   // Point s(4, 6);
   // A.reflex(s);
   // A.Display();
   // cout << endl;*/
   // Polygon X(l);
   // Line f(1, -6);
   // X.reflex(f);
   // X.Display();
    return 0;
}