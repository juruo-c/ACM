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

const int N = 65, M = 2100, mod = 998244353;

int n, k, t;
int f[N][N][M];
int jc[N], jc_inv[N];

int qpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1) res = 1LL * res * a % mod;
        a = 1LL * a * a % mod;
        b >>= 1;
    }
    return res;
}

int C(int n, int m)
{
    if (n < m) return 0;
    return 1LL * jc[n] * jc_inv[m] % mod * jc_inv[n - m] % mod;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    cin >> n >> k >> t;

    jc[0] = jc_inv[0] = 1;
    for (int i = 1; i <= n; i ++ )
        jc[i] = 1LL * jc[i - 1] * i % mod;
    jc_inv[n] = qpow(jc[n], mod - 2);
    for (int i = n - 1; i >= 1; i -- )
        jc_inv[i] = 1LL * jc_inv[i + 1] * (i + 1) % mod;

    for (int i = 0; i <= n; i ++ )
        f[0][i][C(i, 2) + i] = C(n, i);
    
    for (int i = 0; i < k; i ++ )
        for (int j = 0; j <= n; j ++ )
            for (int p = 0; p <= t; p ++ )
                if (f[i][j][p])
                {
                    // printf("i = %d j = %d p = %d f[i][j][p] = %d\n", i, j, p, f[i][j][p]);
                    for (int s = 0; s + j <= n; s ++ )
                    {
                        int x = j + s, y = p + C(s, 2);
                        f[i + 1][x][y] = (f[i + 1][x][y] + 1LL * f[i][j][p] * C(n - j, s) % mod) % mod;
                    }
                }

    cout << f[k - 1][n][t] << endl;

    return 0;
}
