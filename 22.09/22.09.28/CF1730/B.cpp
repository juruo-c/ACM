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
typedef pair<double, double> PDD;

const double eps = 1e-6;

PDD solve(vector<int>& x, vector<int>& t, double x0, int n)
{
    double ltime = 0, rtime = 0;
    for (int i = 0; i < n; i ++ )
        if (x[i] <= x0)
            ltime = max(x0 - x[i] + t[i], ltime);
        else rtime = max(x[i] - x0 + t[i], rtime);
    return make_pair(ltime, rtime);
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
        int n;
        scanf("%d", &n);
        vector<int> x(n);
        double l = 1e9, r = -1;
        for (int i = 0; i < n; i ++ )
            scanf("%d", &x[i]), l = min(l, 1.0 * x[i]), r = max(1.0 * x[i], r);
        vector<int> t(n);
        for (int i = 0; i < n; i ++ )
            scanf("%d", &t[i]);
        
        bool flag = false;
        while (r - l > eps)
        {
            double mid = (l + r) / 2;
            PDD tt = solve(x, t, mid, n);
            if (tt.first > tt.second) r = mid;
            else if (tt.first < tt.second) l = mid;
            else 
            {
                printf("%.10f\n", mid);
                flag = true;
                break;
            }
        }
        if (flag) continue;
        printf("%.10f\n", l);
    }
    return 0;
}
