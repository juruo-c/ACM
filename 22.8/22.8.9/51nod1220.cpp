#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <unordered_map>
#define ZYCMH

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1000000, mod = 1000000007;

int n;
LL p[N + 5], miu[N + 5], g[N + 5], f[N + 5];
bool vis[N + 5];
unordered_map<LL, LL> sum_miu;
LL inv2;

LL qpow(LL a, LL b)
{
    LL res = 1;
    while (b)
    {
        if (b & 1) res = 1LL * res * a % mod;
        b >>= 1;
        a = 1LL * a * a % mod;
    }
    return res;
}

void pre()
{
    g[1] = f[1] = miu[1] = 1;
    for (int i = 2; i <= N; i ++ )
    {
        if (!vis[i])
        {
            p[++ p[0]] = i;
            miu[i] = -1;
            g[i] = i + 1, f[i] = i + 1;
        }
        for (int j = 1; j <= p[0] && 1LL * i * p[j] <= N; j ++ )
        {
            vis[i * p[j]] = true;
            if (i % p[j] == 0)
            {
                miu[i * p[j]] = 0;
                g[i * p[j]] = (1LL * g[i] * p[j] % mod + 1) % mod;
                f[i * p[j]] = 1LL * f[i] * qpow(g[i], mod - 2) % mod * g[i * p[j]] % mod;
                break;
            }
            miu[i * p[j]] = - miu[i];
            f[i * p[j]] = 1LL * f[i] * f[p[j]] % mod;
            g[i * p[j]] = (p[j] + 1) % mod;
        }
    }
    for (int i = 1; i <= N; i ++ )
        f[i] = (f[i] + f[i - 1]) % mod;
    for (int i = 1; i <= N; i ++ )
        miu[i] = (1LL * i * miu[i] % mod + miu[i - 1]) % mod;
}

LL g_sum(LL n)
{
    return 1LL * n * (n + 1) % mod * inv2 % mod;
}

LL get_sum_miu(LL n)
{
    if (n <= N) return miu[n];
    if (sum_miu.find(n) != sum_miu.end()) return sum_miu[n];
    LL ans = 1;
    for (LL l = 2, r; l <= n; l = r + 1)
    {
        r = n / (n / l);
        ans = (ans - (g_sum(r) - g_sum(l - 1) + mod) % mod * get_sum_miu(n / l) % mod + mod) % mod;
    }
    return sum_miu[n] = ans;
}

LL calc(LL n)
{
    if (n <= N) return 1LL * f[n] * f[n] % mod;
    LL ans = 0;
    for (LL l = 1, r; l <= n; l = r + 1)
    {
        r = n / (n / l);
        ans = (ans + 1LL * (r - l + 1) * (l + r) % mod * inv2 % mod * (n / l) % mod) % mod;
    }
    return 1LL * ans * ans % mod;
}

int main()
{
    pre();
    inv2 = qpow(2, mod - 2);
    scanf("%d", &n);
    LL ans = 0;
    for (LL l = 1, r; l <= n; l = r + 1)
    {
        r = n / (n / l);
        ans = (ans + 1LL * (get_sum_miu(r) - get_sum_miu(l - 1)) * calc(n / l) % mod) % mod;
    }
    printf("%lld\n", (ans % mod + mod) % mod);
    return 0;
}
