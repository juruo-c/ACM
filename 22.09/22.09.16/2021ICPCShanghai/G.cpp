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

const int N = 100005, mod = 998244353;

struct edge
{
    int to, next;
}e[N << 1];
int head[N], cnt;
int ans = 1;
int jc[N], jc_inv[N];
int pow2[N];

void add(int u, int v)
{
    e[++ cnt] = {v, head[u]};
    head[u] = cnt;
}

int f(int n)
{
    return 1LL * jc[n] * jc_inv[n / 2] % mod * pow2[n / 2] % mod;
}

bool dfs(int u, int ff)
{
    int res = 0;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == ff) continue;
        if (dfs(v, u)) res ++;
    }
    if (res & 1) 
    {
        res ++;
        ans = 1LL * ans * f(res) % mod;
        return false;
    }
    ans = 1LL * ans * f(res) % mod;
    return true;
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
    int n;
    scanf("%d", &n);

    jc[0] = 1, jc_inv[0] = 1;
    for (int i = 1; i <= n; i ++ )
        jc[i] = 1LL * jc[i - 1] * i % mod;
    jc_inv[n] = qpow(jc[n], mod - 2);
    for (int i = n - 1; i >= 1; i -- )
        jc_inv[i] = 1LL * (i + 1) * jc_inv[i + 1] % mod;
    int inv2 = qpow(2, mod - 2);
    pow2[0] = 1;
    for (int i = 1; i <= n; i ++ )
        pow2[i] = 1LL * pow2[i - 1] * inv2 % mod;

    for (int i = 1; i < n; i ++ )
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }

    dfs(1, 0);

    printf("%d\n", ans);

    return 0;
}