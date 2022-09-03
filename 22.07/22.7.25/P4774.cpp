#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#define ZY

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100005, mod = 1000000007;

int n, m;
LL a[N], p[N], w[N], atk[N], c[N], A[N];
LL ai[N], mi[N];

LL exgcd(LL a, LL b, LL& x, LL& y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    LL g = exgcd(b, a % b, x, y);
    LL z = x;
    x = y;
    y = z - (a / b) * y;
    return g;
}

LL mul(LL x, LL y, LL p)
{
    if (y < 0) x = - x, y = - y;
    LL z = (long double) x / p * y;
    LL res = (unsigned long long) x * y - (unsigned long long) z * p;
    return (res + p) % p;
}

bool solve()
{
    LL x, y;
    for (int i = 1; i <= n; i ++ )
    {
        LL Ai = A[i], b = p[i], c = a[i];
        LL g = exgcd(Ai, b, x, y);
        if (c % g) return false;
        b /= g;
        c /= g;
        x = mul(x, c, b);
        ai[i] = (x % b + b) % b;
        mi[i] = b;
    }
    return true;
}

LL excrt(LL ai[], LL mi[])
{
    LL x, y, k;
    LL M = mi[1], ans = ai[1];
    for (int i = 2; i <= n; i ++ )
    {
        LL a = M, b = mi[i], c = (ai[i] - ans % b + b) % b;
        LL g = exgcd(a, b, x, y);
        if (c % g) return -1;
        b /= g;
        c /= g;
        x = mul(x, c, b);
        ans += x * M;
        M *= b;
        ans = (ans % M + M) % M;
    }
    return (ans % M + M) % M;
}

int main()
{
    #ifdef ZY
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int t; scanf("%d", &t);
    while (t --)
    {
        bool big = false;
        multiset<LL> s;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i ++ )
            scanf("%lld", &a[i]);
        for (int i = 1; i <= n; i ++ )
        {
            scanf("%lld", &p[i]);
            if (a[i] > p[i]) big = true;
        }

        for (int i = 1; i <= n; i ++ ) scanf("%lld", &w[i]);
        for (int i = 1; i <= m; i ++ ) scanf("%lld", &atk[i]), s.insert(atk[i]);

        for (int i = 1; i <= n; i ++ )
        {
            multiset<LL>::iterator it = s.begin();
            if (*it > a[i]) A[i] = *it;
            else
            {
                it = s.upper_bound(a[i]);
                it --;
                A[i] = *it;
            }
            s.erase(it);
            s.insert(w[i]);
        }

        if (big)
        {
            LL ans = -1e18;
            for (int i = 1; i <= n; i ++ )
                ans = max(ans, (a[i] + A[i] - 1) / A[i]);
            printf("%lld\n", ans);
            continue;
        }

        if (!solve())
        {
            puts("-1");
            continue;
        }

        printf("%lld\n", excrt(ai, mi));

    }
    return 0;
}
