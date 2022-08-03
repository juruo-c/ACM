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

const int N = 1000005, mod = 998244353;

int n, k, s;
struct edge
{
    int to, next;
}e[N << 1];
int head[N], cnt;
int fa[N], dep[N];
int a[N];
int c[N];
int id[N];

void add(int u, int v)
{
    e[++ cnt] = {v, head[u]};
    head[u] = cnt;
}

void dfs1(int u, int ff)
{
    fa[u] = ff;
    dep[u] = dep[ff] + 1;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == ff) continue;
        dfs1(v, u);
    }
}

void dfs2(int u, int ff)
{
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == ff) continue;
        a[v] += a[u];
        dfs2(v, u);
    }
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

int calc(int l, int r)
{
    if (!l) return c[r];
    return (c[r] - c[l - 1] + mod) % mod;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    scanf("%d%d%d", &n, &k, &s);
    for (int i = 1; i < n; i ++ )
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }

    dep[0] = -1;
    dfs1(1, 0);

    for (int i = s; i; i = fa[i])
        a[i] = 1;

    dfs2(1, 0);

    int tt = a[s];
    for (int i = s; i; i = fa[i])
        id[tt --] = i;
    
    // for (int i = 1; i <= a[s]; i ++ )
    //     cout << "i = " << i << " id[i] = " << id[i] << endl;

    c[0] = 1;
    for (int i = 1; i < n; i ++ )
        c[i] = 1LL * c[i - 1] * (n - i - k) % mod * qpow(n - i, mod - 2) % mod;

    for (int i = 1; i < n; i ++ )
        c[i] = (c[i] + c[i - 1]) % mod;

    int ans = 0;
    for (int i = 2; i <= n; i ++ )
    {
        int tt = id[a[i]];
        int l = dep[i] - dep[tt];
        int len = dep[tt] - 1, r = l + len;
        ans = (ans + 2 * calc(l, r) % mod) % mod;
    }

    printf("%d\n", (ans - dep[s] + mod) % mod);

    return 0;
}
