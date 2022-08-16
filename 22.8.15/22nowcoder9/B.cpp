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

const int N = 8005, mod = 998244353;

int n;
int f[2][N];
int a[N];
int p[N];

void add(int id, int x, int k)
{
    // printf("id = %d x = %d k = %d\n", id, x, k);
    for (int i = x; i <= n; i += (i & -i))
        f[id][i] = (f[id][i] + k) % mod;   
}

int query(int id, int x)
{
    int res = 0;
    for (int i = x; i; i -= (i & -i))
        res = (res + f[id][i]) % mod;
    return res;
}

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

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    scanf("%d", &n);
    for (int i = 1; i < n; i ++ )
        scanf("%d", &a[i]), p[i] = qpow(a[i], mod - 2);

    add(0, 1, 1);
    add(0, 2, -1);
    LL ans = 0;
    for (int i = 0; i < n; i ++ )
    {
        int t = query(i & 1, n);
        ans = (ans + 1LL * t * t % mod) % mod;
        memset(f[i + 1 & 1], 0, sizeof f[i + 1 & 1]);
        for (int j = 1; j < n; j ++ )
        {
            t = query(i & 1, j);
            if (t)
            {
                int P = 1LL * t * p[j] % mod;
                // printf("i = %d j = %d t = %d p = %d i + 1 & 1 = %d\n", i, j, t, P, i + 1 & 1);
                add(i + 1 & 1, j + 1, P);
                add(i + 1 & 1, j + a[j] + 1, - P);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
