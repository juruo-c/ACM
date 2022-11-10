#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const double EPS = 1e-8;
const double INF = 1e100;

int sgn(double s)
{
    if (fabs(s) < EPS) return 0;
    if (s > 0) return 1;
    return -1;
}

int cmp(double x, double y)
{
    if (fabs(x - y) < EPS) return 0;
    if (x < y) return -1;
    return 1;
}

struct Point 
{
    double x, y;
    Point(double x = 0.0, double y = 0.0):x(x), y(y){}
    void input()
    {
        scanf("%lf%lf", &x, &y);
    }

    Point operator + (Point b)
    {
        return Point(x + b.x, y + b.y);
    }
    Point operator - (Point b)
    {
        return Point(x - b.x, y - b.y);
    }
    Point operator * (double b)
    {
        return Point(x * b, y * b);
    }
    Point operator * (Point b)
    {
        return x * b.x + y * b.y;
    }
    Point operator / (double b)
    {
        return Point(x / b, y / b);
    }
    bool operator == (const Point& b)
    {
        return cmp(x, b.x) == 0 && cmp(y, b.y) == 0;
    }
    double cross(Point b) const 
    {
        return x * b.y - y * b.x;
    }
    double length()
    {
        return sqrt(x * x + y * y);
    }  
};

typedef Point Vector;

struct Line
{
    Point pos;
    Vector to;
    Line(Point p = Point(), Vector t = Point()) : pos(p), to(t){}
    static Line tp(Point& a, Point& b)
    {
        return Line(a, b - a);
    }
    bool onLine(Point s)
    {
        return sgn(to.cross(s - pos)) == 0;
    }
};

const int N = 30000;

int n;
Point p[N];
Point c[5];

bool check(int m)
{
    Point P = c[m];
    for (int i = 0; i < 5; i ++ )
    {
        if (i == m) continue;
        Vector v = c[i] - P;
        v = v / v.length();
        for (int j = 0; j < i; j ++ )
        {
            if (j == m) continue;
            if (v == (c[j] - P) / (c[j] - P).length()) return false;
        }
    }
    printf("%.0f %.0f\n", P.x, P.y);
    for (int i = 0; i < 5; i ++ )
    {
        if (i == m) continue;
        printf("%.0f %.0f\n", c[i].x, c[i].y);
    }
    return true;
}

int main()
{
    int _;
    scanf("%d", &_);
    while (_ --)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++ )
            p[i].input();
        if (n < 5) {
            puts("NO");
            continue;
        }
        Line l = Line::tp(p[1], p[2]);
        bool flag = false;
        for (int i = 3; i <= n; i ++ )
        {
            if (!l.onLine(p[i]))
            {
                c[0] = p[i];
                int k = 1;
                for (int j = i - 1; j >= 1 && k <= 4; j --, k ++)
                    c[k] = p[j];
                for (int j = i + 1; j <= n && k <= 4; j ++, k ++)
                    c[k] = p[j];
                flag = true;
                break;
            }
        }
        if (!flag) puts("NO");
        else 
        {
            puts("YES");
            for (int i = 0; i < 5; i ++ )
            {
                if (check(i))
                    break;
            }
        }
    }
    return 0;
}