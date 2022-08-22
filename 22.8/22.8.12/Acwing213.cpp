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

const int N = 40000, mod = 999911659;

LL ai[5];
LL mi[5] = {0, 2, 3, 4679, 35617};
LL inv[N + 5], jc[N + 5];

LL mul(LL x, LL y, LL p)
{
    if (y < 0) x = -x, y = -y;
    LL z = (long double) x / p * y;
    LL res = (unsigned long long)x * y - (unsigned long long)z * p;
    return (res % p + p) % p;
}

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
    y = z - y * (a / b);
    return g;
}

LL crt(int n)
{
    LL M = 1;
    for (int i = 1; i <= n; i ++ ) M *= mi[i];
    LL res = 0;
    for (int i = 1; i <= n; i ++ )
    {
        LL Mi = M / mi[i];
        LL _Mi, y;
        LL d = exgcd(Mi, mi[i], _Mi, y);
        _Mi = (_Mi % mi[i] + mi[i]) % mi[i];
        res += mul(mul(ai[i], _Mi, M), Mi, M);
    }
    return (res % M + M) % M;
}

LL qpow(LL a, LL b, LL p)
{
    LL res = 1;
    while (b)
    {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

LL C(LL n, LL m, LL p)
{
    // cout << "C: " << "n = " << n << " m = " << m << endl;
    if (n < m) return 0;
    // printf("jc[n] = %d inv[m] = %d inv[n - m] = %d\n", jc[n], inv[m], inv[n - m]);
    // printf("jc[%d] * inv[%d] * inv[%d] = %d\n", n, m, n - m, jc[n] * inv[m] % p * inv[n - m] % p);
    return jc[n] * inv[m] % p * inv[n - m] % p;
}

LL Lucas(LL n, LL m, LL p)
{
    // cout << "n = " << n << " m = " << m << endl;
    if (n < m) return 0;
    if (n == m || !m) return 1;
    return Lucas(n / p, m / p, p) * C(n % p, m % p, p) % p;
}

void calc(LL& res, LL p, int n)
{
    jc[0] = 1, inv[0] = 1;
    for (int i = 1; i < p; i ++ ) jc[i] = jc[i - 1] * i % p;
    inv[p - 1] = qpow(jc[p - 1], p - 2, p);
    for (int i = p - 2; i >= 1; i -- ) inv[i] = inv[i + 1] * (i + 1) % p;

    for (int i = 1; i * i <= n; i ++ )
        if (n % i == 0)
        {
            // printf("Lucas(%d, %d, %lld) = %lld\n", n, i, p, Lucas(n, i, p));
            res = (res + Lucas(n, i, p)) % p;
            if (i * i != n)
                res = (res + Lucas(n, n / i, p)) % p;//printf("Lucas(%d, %d, %d) = %d\n", n, n / i, p, Lucas(n, n / i, p));
        }
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif

    int n, q;
    cin >> n >> q;

    if (q % mod == 0) 
    {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 1; i <= 4; i ++ )
        calc(ai[i], mi[i], n);

    LL t = crt(4);

    cout << qpow(q, t, mod) << endl;

    // cout << Lucas(4, 4, 2);

    return 0;
}
