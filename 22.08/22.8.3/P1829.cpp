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

const int N = 10000005, mod = 20101009;

int n, m;
int p[N], miu[N];
bool vis[N];
LL miuS[N];

void getmiu()
{
    miu[1] = 1;
    for (int i = 2; i < N; i ++ )
    {
        if (!vis[i])
        {
            p[++ p[0]] = i;
            miu[i] = -1;
        }
        for (int j = 1; j <= p[0] && 1LL * i * p[j] < N; j ++ )
        {
            vis[i * p[j]] = true;
            if (i % p[j] == 0)
            {
                miu[i * p[j]] = 0;
                break;
            }
            miu[i * p[j]] = - miu[i];
        }
    }

    for (int i = 1; i < N; i ++ )
        miuS[i] = (miuS[i - 1] + 1LL * miu[i] * i % mod * i % mod) % mod;
}

LL qpow(int a, int b)
{
    LL res = 1;
    while (b)
    {
        if (b & 1) res = res * a % mod;
        a = 1LL * a * a % mod;
        b >>= 1;
    }
    return res;
}

LL g(LL n, LL m)
{
    return 1LL * (m + 1) * m % mod * (n + 1) % mod * n % mod * qpow(4, mod - 2) % mod;
}

LL f(LL n, LL m)
{
    LL ans = 0;
    for (int l = 1, r; l <= n; l = r + 1)
    {
        r = min(n / (n / l), m / (m / l));
        ans = (ans + 1LL * (miuS[r] - miuS[l - 1]) * g(n / l, m / l) % mod) % mod;
    }
    return ans;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    getmiu();
    int n, m;
    scanf("%d%d", &n, &m);
    if (n > m) swap(n, m);

    LL ans = 0;
    for (int l = 1, r; l <= n; l = r + 1)
    {
        r = min(n / (n / l), m / (m / l));
        ans = (ans + 1LL * (l + r) * (r - l + 1) % mod * qpow(2, mod - 2) % mod * f( n / l, m / l) % mod) % mod;
    }

    printf("%lld\n", (ans + mod) % mod);

    return 0;
}
