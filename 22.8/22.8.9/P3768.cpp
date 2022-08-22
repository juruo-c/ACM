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

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 4641590;

LL n;
int mod;
bool vis[N + 5];
LL p[N + 5], phi[N + 5];
LL inv2, inv4, inv6;
unordered_map<LL, LL> sum_phi;

void getphi()
{
    phi[1] = 1;
    for (LL i = 2; i <= N; i ++)
    {
        if (!vis[i])
        {
            p[++ p[0]] = i;
            phi[i] = i - 1;
        }
        for (int j = 1; j <= p[0] && i * p[j] <= N; j ++ )
        {
            vis[i * p[j]] = true;
            if (i % p[j] == 0)
            {
                phi[i * p[j]] = phi[i] * p[j] % mod;
                break;
            }
            phi[i * p[j]] = phi[i] * (p[j] - 1) % mod;
        }
    }
    for (int i = 1; i <= N; i ++ )
        phi[i] = (phi[i] + phi[i - 1]) % mod;
}

LL qpow(LL a, LL b)
{
    LL res = 1;
    while (b)
    {
        if (b & 1) res = res * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}

inline LL sum(LL n)
{
    return n % mod * (n + 1) % mod * inv2 % mod;
}

inline LL g_sum(LL n)
{
    return (n + 1) % mod * n % mod * (2 * n + 1) % mod * inv6 % mod;
}

inline LL h_sum(LL n)
{
    return (n + 1) % mod * (n + 1) % mod * n % mod * n % mod * inv4 % mod;
}

LL get_sum(LL n)
{
    if (n <= N) return phi[n];
    if (sum_phi[n]) return sum_phi[n];
    LL ans = h_sum(n);
    for (LL l = 2, r; l <= n; l = r + 1)
    {
        r = n / (n / l);
        ans = (ans - (g_sum(r) - g_sum(l - 1) + mod) % mod * get_sum(n / l) % mod + mod) % mod;
    }
    return sum_phi[n] = ans;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    scanf("%lld%d", &n, &mod);
    inv2 = qpow(2, mod - 2), inv4 = qpow(4, mod - 2), inv6 = qpow(6, mod - 2);
    getphi();

    LL ans = 0;
    for (LL l = 1, r; l <= n; l = r + 1)
    {
        r = n / (n / l);
        ans = (ans + sum(n / l) * sum(n / l) % mod * ((get_sum(r) - get_sum(l - 1) + mod) % mod) % mod)  % mod;
        printf("%lld\n", ans);
    }

    printf("%lld\n", (ans % mod + mod) % mod);

    return 0;
}
