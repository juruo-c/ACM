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

const int N = 65, mod = 998244353;

int f[N], g[N];
int jc[N], jc_inv[N];

int C(int n, int m)
{
    return 1LL * jc[n] * jc_inv[m] % mod * jc_inv[n - m] % mod;
}

int qpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1) res = 1LL * res * a % mod;
        b >>= 1;
        a = 1LL * a * a % mod;
    }
    return res;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif

    jc[0] = jc_inv[0] = 1;
    for (int i = 1; i <= 60; i ++ )
        jc[i] = 1LL * i * jc[i - 1] % mod;
    jc_inv[60] = qpow(jc[60], mod - 2);
    for (int i = 59; i >= 1; i -- )
        jc_inv[i] = 1LL * (i + 1) * jc_inv[i + 1] % mod;

    f[2] = 1, g[2] = 0;
    for (int i = 4; i <= 60; i ++ )
        f[i] = ((C(i - 2, (i - 2) / 2) - f[i - 2] - 1 + mod) % mod + C(i - 1, i / 2)) % mod;

    int _; scanf("%d", &_);
    while (_ --)
    {
        int n;
        scanf("%d", &n);
        printf("%d %d %d\n", f[n], (C(n, n / 2) - f[n] - 1 + mod) % mod, 1);
    }
    return 0;
}
