#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#define ZYCMH

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1005;

int n, m;
int xs, ys, xt, yt;
int x[N], y[N];

struct Node
{
    double x, y;
    double s;
    bool operator < (const Node& b) const
    {
        return s < b.s;
    }
}a[N];

double getk(double x1, double y1, double x2, double y2)
{
    if (x1 == x2) return -1;
    return 1.0 * (y1 - y2) / (x1 - x2);
}

double getb(double x, double y, double k)
{
    return y - k * x;
}

double getdis(double x1, double y1, double x2, double y2)
{
    double dx = x1 - x2, dy = y1 - y2;
    return dx * dx + dy * dy;
}

void getPoint(double& X, double& Y, double k1, double b1, double k2, double b2)
{
    if (k1 == k2){
        X = Y = 1e18;
        return;
    }
    if (k1 == -1.0)
    {
        X = b1;
        Y = k2 * X + b2;
    }
    else if (k2 == -1.0)
    {
        X = b2;
        Y = k1 * X + b1;
    }
    else 
    {
        X = (b2 - b1) / (k1 - k2);
        Y = k1 * X + b1;
    }
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    
    scanf("%d%d", &n, &m);
    scanf("%d%d%d%d", &xs, &ys, &xt, &yt);
    for (int i = 1; i <= n; i ++ )
        scanf("%d%d", &x[i], &y[i]);

    double Kst = getk(xs, ys, xt, yt);
    double Bst;
    if (Kst != -1.0)
        Bst = getb(xs, ys, Kst);
    else Bst = xs;

    

    for (int i = 1; i <= m; i ++ )
    {
        int hi, ki;
        scanf("%d%d", &hi, &ki);
        int xi = x[hi], yi = y[hi];

        int cnt = 0;
        for (int j = 1; j <= n; j ++ )
            if (j != hi)
            {
                double K = getk(xi, yi, x[j], y[j]);
                double B;
                if (K != -1.0) B = getb(xi, yi, K);
                else B = xi;

                // printf("xi = %d yi = %d x[j] = %d y[j] = %d K = %.2f B = %.2f ", xi, yi, x[j], y[j], K, B);
                
                double X, Y;
                getPoint(X, Y, K, B, Kst, Bst);
                // printf("X = %.2f Y = %.2f\n", X, Y);
                if (min(xs, xt) <= X && X <= max(xs, xt)) 
                    a[++ cnt] = {X, Y, getdis(X, Y, xs, ys)};
            }
        if (cnt < ki)
            puts("-1");
        else 
        {
            sort(a + 1, a + 1 + cnt);
            printf("%.10f %.10f\n", a[ki].x, a[ki].y);
        }
    }

    return 0;
}
