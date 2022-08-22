#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>

using namespace std;

const int N = 100005;

int n;
double a[N];

int main()
{
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    int t; scanf("%d", &t);
    while (t --)
    {
        scanf("%d", &n);
        double ybar = 0, xbar = 0, x2sum = 0;
        for (int i = 1; i <= n; i ++ ) scanf("%Lf", &a[i]), ybar += a[i], xbar += i, x2sum += (long double)i * i;
        xbar /= n, ybar /= n;

        double w = 0;
        for (int i = 1; i <= n; i ++ )
            w += a[i] * (i - xbar);
        
        w /= (x2sum - xbar * n * xbar);
        double b = ybar - w * xbar;

        double E = 0;
        for (int i = 1; i <= n; i ++ )
            E += (a[i] - (w * i + b)) * (a[i] - (w * i + b));
        printf("%.10Lf\n", E);
    }
    return 0;
}