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

const int N = 2005, mod = 998244353;

int x[N], y[N];

int qpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1) res = 1LL * res * a % mod;
        b >>=1;
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
    int n, k;
    scanf("%d%d", &n, &k);

    for (int i = 1; i <= n; i ++ ) 
        scanf("%d%d", &x[i], &y[i]);

    int ans = 0;
    for (int i = 1; i <= n; i ++ )
    {
        int res = y[i], down = 1;
        for (int j = 1; j <= n; j ++ )
            if (j != i)
            {
                res = 1LL * res * (k - x[j]) % mod, res = (res + mod) % mod;
                down = 1LL * down * (x[i] - x[j]) % mod, down = (down + mod) % mod;
            }
        ans = (ans + 1LL * res * qpow(down, mod - 2) % mod) % mod;
    }

    printf("%d\n", ans);

    return 0;
}
