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

int n;

bool check(vector<int>& a, vector<int>& b, int x)
{
    vector<int> c(n), d(n);
    for (int i = 0; i < n; i ++ )
    {
        c[i] = a[i] & x;
        d[i] = (~b[i]) & x;
    }
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());
    return c == d;
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
        scanf("%d", &n);
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);
        for (int i = 0; i < n; i ++ ) scanf("%d", &b[i]);

        int ans = 0;
        for (int i = 29; i >= 0; i -- )
        {
            if (check(a, b, ans + (1 << i)))
                ans += 1 << i;
        }

        printf("%d\n", ans);

    }
    return 0;
}
