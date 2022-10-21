#include <iostream>
#include <cmath>

using namespace std;

const double eps = 1e-8;

int sgn(double x)
{
    if (fabs(x) < eps) return 0;
    else return x < 0 ? -1 : 1;
}

struct Point
{
    double x, y;
    Point(){}
    Point(double x, double y):x(x), y(y){}
    Point operator - (const Point& b) const
    {
        return Point(x - b.x, y - b.y);
    }
}p[5];

struct Line
{
    Point p1, p2;
    Line(){}
    Line(Point p1, Point p2):p1(p1), p2(p2){}
}l[5];

double Dist(Point a, Point b)
{
    double dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

double Dot(Point a, Point b)
{
    return a.x * b.x + a.y * b.y;
}

double Cross(Point a, Point b)
{
    return a.x * b.y - a.y * b.x;
}

bool Point_on_Line(Point P, Line L)
{
    return sgn(Cross(P - L.p1, L.p2 - L.p1)) == 0 && sgn(Dot(P - L.p1, P - L.p2)) <= 0;
}

double getmid(double a, double b)
{
    return (a + b) / 2;
}

struct Node
{
    Point p1, p2;
    double d;
};

Node solve()
{
    Node res;

    if (Point_on_Line(p[4], l[1]))
    {
        if (Dist(p[1], p[4]) < Dist(p[2], p[4]))
        {
            res.p1 = p[2], res.p2 = p[3];
            res.d = Dist(p[1], p[2]) / Dist(p[4], p[2]) / 2;
        }
        else  
        {
            res.p1 = p[1], res.p2 = p[3];
            res.d = Dist(p[1], p[2]) / Dist(p[4], p[1]) / 2;
        }
    }
    else if(Point_on_Line(p[4], l[3]))
    {
        if (Dist(p[3], p[4]) < Dist(p[1], p[4]))
        {
            res.p1 = p[1], res.p2 = p[2];
            res.d = Dist(p[1], p[3]) / Dist(p[4], p[1]) / 2;
        }
        else  
        {
            res.p1 = p[3], res.p2 = p[2];
            res.d = Dist(p[1], p[3]) / Dist(p[4], p[3]) / 2;
        }
    }
    else 
    {
        if (Dist(p[2], p[4]) < Dist(p[3], p[4]))
        {
            res.p1 = p[3], res.p2 = p[1];
            res.d = Dist(p[2], p[3]) / Dist(p[4], p[3]) / 2;
        }
        else  
        {
            res.p1 = p[2], res.p2 = p[1];
            res.d = Dist(p[2], p[3]) / Dist(p[4], p[2]) / 2;
        }
    }

    return res;
}

int main()
{
    int _;
    scanf("%d", &_);
    while (_ --)
    {
        for (int i = 1; i <= 4; i ++ )
            scanf("%lf%lf", &p[i].x, &p[i].y);
        if (p[1].x == p[4].x && p[1].y == p[4].y)
        {
            printf("%.10f %.10f\n", getmid(p[2].x, p[3].x), getmid(p[2].y, p[3].y));
            continue;
        }
        if (p[2].x == p[4].x && p[2].y == p[4].y)
        {
            printf("%.10f %.10f\n", getmid(p[1].x, p[3].x), getmid(p[1].y, p[3].y));
            continue;
        }
        if (p[3].x == p[4].x && p[3].y == p[4].y)
        {
            printf("%.10f %.10f\n", getmid(p[1].x, p[2].x), getmid(p[1].y, p[2].y));
            continue;
        }

        l[1] = Line(p[1], p[2]);
        l[2] = Line(p[2], p[3]);
        l[3] = Line(p[3], p[1]);

        if (!Point_on_Line(p[4], l[1]) && !Point_on_Line(p[4], l[2]) && !Point_on_Line(p[4], l[3]))
        {
            puts("-1");
            continue;
        }

        if (Point_on_Line(p[4], l[1]) && p[4].x == getmid(p[1].x, p[2].x) && p[4].y == getmid(p[1].y, p[2].y))
        {
            printf("%.10f %.10f\n", p[3].x, p[3].y);
            continue;
        }
        if (Point_on_Line(p[4], l[2]) && p[4].x == getmid(p[3].x, p[2].x) && p[4].y == getmid(p[3].y, p[2].y))
        {
            printf("%.10f %.10f\n", p[1].x, p[1].y);
            continue;
        }
        if (Point_on_Line(p[4], l[3]) && p[4].x == getmid(p[1].x, p[3].x) && p[4].y == getmid(p[1].y, p[3].y))
        {
            printf("%.10f %.10f\n", p[2].x, p[2].y);
            continue;
        }
        
        Node res = solve();

        Point p1 = res.p1, p2 = res.p2;
        double a = res.d;

        printf("%.10f %.10f\n", a * (p2 - p1).x + p1.x, a * (p2 - p1).y + p1.y);

    }
    return 0;
}