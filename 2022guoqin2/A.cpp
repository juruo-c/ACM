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

const int N = 305;

int n, m, k, t;
LL f[N][N];
bool is[N];
int fa[N];

int getf(int x)
{
    return x == fa[x] ? x : fa[x] = getf(fa[x]);
}

bool check(LL x)
{
    for (int i = 1; i <= n; i ++ ) fa[i] = i;
    
    for (int i = 1; i <= n; i ++ )
    {
        if (!is[i]) continue;
        for (int j = 1; j <= n; j ++ )
        {
            if (!is[j] || j == i || f[i][j] == 1e18) continue;
            if (1.0 * f[i][j] / x > t) continue;
            int fi = getf(i), fj = getf(j);
            if (fi != fj)
                fa[fi] = fj;
        }
    }

    for (int i = 1; i <= n; i ++ )
    {
        if (is[i]) continue;
        for (int j = 1; j <= n; j ++ )
        {
            if (!is[j] || j == i || f[i][j] == 1e18) continue;
            if (2.0 * f[i][j] / x > t) continue;
            int fi = getf(i), fj = getf(j);
            if (fi != fj)
                fa[fi] = fj;
        }
    }

    for (int i = 1; i <= n; i ++ )
        if (getf(i) != getf(1))
            return false;
    return true;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    
    scanf("%d%d%d%d", &n, &m, &k, &t);

    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            if (i != j)
                f[i][j] = 1e18;

    for (int i = 1; i <= n; i ++ )
        fa[i] = i;
    for (int i = 1; i <= m; i ++ )
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        f[u][v] = f[v][u] = w;
        u = getf(u), v = getf(v);
        if (u != v)
            fa[u] = v;
    }

    for (int p = 1; p <= n; p ++ )
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= n; j ++ )
                f[i][j] = min(f[i][j], f[i][p] + f[p][j]);

    // for (int i = 1; i <= n; i ++ )
    // {
    //     for (int j = 1; j <= n; j ++ )
    //         printf("%lld ", f[i][j]);
    //     puts("");
    // }

    for (int i = 1; i <= k; i ++ )
    {
        int x;
        scanf("%d", &x);
        is[x] = true;
    }

    if (!t)
    {
        puts("-1");
        return 0;
    }

    bool flag = true;
    for (int i = 1; i <= n; i ++ )
        if (getf(i) != getf(1))
        {
            flag = false;
            break;
        }

    if (!flag)
    {
        puts("-1");
        return 0;
    }

    LL l = 1, r = 1e18;
    while (l < r)
    {
        LL mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }

    printf("%lld\n", r);

    return 0;
}
