//http://oj.daimayuan.top/course/10/problem/467
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 3005, M = 2000005, mod = 1000000007;

int n, m;
LL fac[M], facinv[M];
LL f[N];
struct Point
{
    int x, y;
    bool operator < (const Point& p) const{
        if (y == p.y)
            return x < p.x;
        return y < p.y;
    }
}p[N];

LL C(int n, int m)
{
    return fac[n] * facinv[m] % mod * facinv[n - m] % mod;
}

LL qpow(LL a, int b)
{
    LL res = 1;
    while (b)
    {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i ++ )
        scanf("%d%d", &p[i].x, &p[i].y);
    sort(p + 1, p + 1 + m);
    p[0] = {1, 1}, p[m + 1] = {n, n};

    fac[0] = facinv[0] = 1;
    for (int i = 1; i <= 2 * n; i ++ )
        fac[i] = fac[i - 1] * i % mod;
    facinv[2 * n] = qpow(fac[2 * n], mod - 2);
    for (int i = 2 * n - 1; i >= 1; i -- )
        facinv[i] = facinv[i + 1] * (i + 1) % mod;

    for (int i = 1; i <= m + 1; i ++ )
    {
        f[i] = C(p[i].x + p[i].y - 2, p[i].x - 1);
        for (int j = 1; j < i; j ++ )
        {
            if (p[j].x > p[i].x) continue;
            f[i] = (f[i] - f[j] * C(p[i].x + p[i].y - p[j].x - p[j].y, p[i].x - p[j].x) % mod + mod) % mod;
        }
    }

    printf("%lld\n", f[m + 1]);

    return 0;
}
