#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 15, mod = 1000000007;

LL a[N], b[N];

LL mul(LL x, LL y, LL p)
{
    if (y < 0) x = -x, y = -y;
    LL z = (long double) x / p * y;
    LL res = (unsigned long long) x * y - (unsigned long long) z * p;
    return (res + p) % p;
}

LL exgcd(LL a, LL b, LL& x, LL& y)
{
    if (!b)
    {
        x = 1, y = 0;
        return b;
    }
    LL gcd = exgcd(b, a % b, x, y);
    LL z = x;
    x = y;
    y = z - (a / b) * y;
    return gcd;
}

LL crt(LL a[], LL m[], int n)
{
    LL M = 1;
    for (int i = 1; i <= n; i ++ ) M *= m[i];
    LL res = 0;
    for (int i = 1; i <= n; i ++ )
    {
        LL Mi = M / m[i];
        LL _Mi, y;
        LL d = exgcd(Mi, m[i], _Mi, y);
        _Mi = (_Mi % m[i] + m[i]) % m[i];
        res += mul(mul(a[i], _Mi, M), Mi, M);
    }
    return (res % M + M) % M; //最小非负整数解
}

int main()
{
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    int t = 1;
    while (t --)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++ )
            scanf("%lld", &a[i]);
        for (int i = 1; i <= n; i ++ )
            scanf("%lld", &b[i]);

        for (int i = 1; i <= n; i ++ )
            a[i] = (a[i] % b[i] + b[i]) % b[i];
    
        printf("%lld\n", crt(a, b, n));

    }
    return 0;
}
