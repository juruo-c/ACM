#include <iostream>
#include <cmath>

using namespace std;

typedef pair<double, double> PDD;

double x1, y1, x2, y2, x3, y3;
double px, py;
double S;

bool check(double x1, double y1, double x2, double y2)
{
    if (x1 == x2)
        return px == x1 && min(y1, y2) <= py && py <= max(y1, y2);
    else 
    {
        double k = (y1 - y2) / (x1 - x2);
        double b = y1 - k * x1;
        return k * px + b == py && min(y1, y2) <= py && py <= max(y1, y2) && min(x1, x2) <= px && px <= max(x1, x2);
    }    
}

double getx(double x1, double x2)
{
    return (x1 + x2) / 2;
}

double gety(double y1, double y2)
{
    return (y1 + y2) / 2;
}

double getdis(double x1, double y1, double x2, double y2)
{
    double dx = x1 - x2, dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

struct Node
{
    double x1, x2, y1, y2;
    double d;
};

Node solve()
{
    Node res;

    if (check(x1, y1, x2, y2))
    {
        if (2 * getdis(x1, y1, px, py) < getdis(x1, y1, x2, y2))
        {
            res.x1 = x2, res.y1 = y2, res.x2 = x3, res.y2 = y3;
            res.d = getdis(x1, y1, x2, y2) / getdis(px, py, x2, y2) / 2;
        }
        else  
        {
            res.x1 = x1, res.y1 = y1, res.x2 = x3, res.y2 = y3;
            res.d = getdis(x1, y1, x2, y2) / getdis(px, py, x1, y1) / 2;
        }
    }
    else if(check(x1, y1, x3, y3))
    {
        if (2 * getdis(x3, y3, px, py) < getdis(x1, y1, x3, y3))
        {
            res.x1 = x1, res.y1 = y1, res.x2 = x2, res.y2 = y2;
            res.d = getdis(x1, y1, x3, y3) / getdis(px, py, x1, y1) / 2;
        }
        else  
        {
            res.x1 = x3, res.y1 = y3, res.x2 = x2, res.y2 = y2;
            res.d = getdis(x1, y1, x3, y3) / getdis(px, py, x3, y3) / 2;
        }
    }
    else 
    {
        if (2 * getdis(x2, y2, px, py) < getdis(x3, y3, x2, y2))
        {
            res.x1 = x3, res.y1 = y3, res.x2 = x1, res.y2 = y1;
            res.d = getdis(x3, y3, x2, y2) / getdis(px, py, x3, y3) / 2;
        }
        else  
        {
            res.x1 = x2, res.y1 = y2, res.x2 = x1, res.y2 = y1;
            res.d = getdis(x3, y3, x2, y2) / getdis(px, py, x2, y2) / 2;
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
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3, &px, &py);
        if (x1 == px && y1 == py)
        {
            printf("%.10f %.10f\n", getx(x2, x3), gety(y2, y3));
            continue;
        }
        if (x2 == px && y2 == py)
        {
            printf("%.10f %.10f\n", getx(x1, x3), gety(y1, y3));
            continue;
        }
        if (x3 == px && y3 == py)
        {
            printf("%.10f %.10f\n", getx(x1, x2), gety(y1, y2));
            continue;
        }
        if (!check(x1, y1, x2, y2) && !check(x1, y1, x3, y3) && !check(x2, y2, x3, y3))
        {
            puts("-1");
            continue;
        }

        if (check(x1, y1, x2, y2) && px == getx(x1, x2) && py == gety(y1, y2))
        {
            printf("%.10f %.10f\n", x3, y3);
            continue;
        }

        if (check(x2, y2, x3, y3) && px == getx(x2, x3) && py == gety(y2, y3))
        {
            printf("%.10f %.10f\n", x1, y1);
            continue;
        }

        if (check(x1, y1, x3, y3) && px == getx(x1, x3) && py == gety(y1, y3))
        {
            printf("%.10f %.10f\n", x2, y2);
            continue;
        }
        
        Node res = solve();

        x1 = res.x1, y1 = res.y1, x2 = res.x2, y2 = res.y2;
        double a = res.d;

        printf("%.10f %.10f\n", x1 + a * (x2 - x1), a * (y2 - y1) + y1);

    }
    return 0;
}