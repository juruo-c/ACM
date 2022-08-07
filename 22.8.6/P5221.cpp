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

const int N = 100005, mod = 1000000007;

int phi[N], p[N];
bool vis[N];

void getphi(int n)
{  
    phi[1] = 1;
    for (int i = 2; i <= n; i ++ )
    {
        if (!vis[i])
        {
            p[ ++ p[0]] = i;
            phi[i] = i - 1;
        }
        for (int j = 1; j <= p[0] && 1LL * i * p[j] <= n; j ++ )
        {
            vis[i * p[j]] = true;
            if (i % p[j] == 0)
            {
                phi[i * p[j]] = 1LL * phi[i] * p[j] % mod;
                break;
            }
            phi[i * p[j]] = 1LL * phi[i] * (p[j] - 1) % mod;
        }
    }
    for (int i = 1; i <= n; i ++ )
        phi[i] = (phi[i] + phi[i - 1]) % mod;
}

int qpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = 1LL * res * a % mod;
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
    int n;
    scanf("%d", &n);
    getphi(n);
    int ans = 1;
    for (int i = 1; i <= n; i ++ )
        ans = 1LL * ans * i % mod;
    ans = qpow(ans, 2 * n);

    int res = 1;
    for (int i = 1; i <= n; i ++ )
    {
        int e = 1LL * 2 * phi[n / i] % (mod - 1);
        e = (e - 1 + mod - 1) % (mod - 1);
        int t = qpow(i, e);
        res = 1LL * res * t % mod;
    }
    res = 1LL * res * res % mod;
    ans = 1LL * ans * qpow(res, mod - 2) % mod;
    printf("%d\n", ans);

    return 0;
}
