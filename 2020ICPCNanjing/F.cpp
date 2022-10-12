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

const double esp = 1e-6;

int n, m;
double p;

double f(double x)
{
    return (x * n + m) / (1 - pow(1 - p, x));
}

double solve()
{
    double l = 1, r = 1e9;
    while (r - l > esp)
    {
        double mid = (l + r) / 2;
        double mmid = (mid + r) / 2;
        if (f(mid) < f(mmid))
            r = mmid;
        else l = mid;
    }
    return min(f((int)l), f((int)l + 1));
}   

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int _; scanf("%d", &_);
    while (_ --)
    {
        scanf("%d%d%lf", &n, &m, &p);
        p /= 10000;
        printf("%.10f\n", solve());
    }
    return 0;
}
