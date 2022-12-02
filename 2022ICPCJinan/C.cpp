#include <bits/stdc++.h>

using namespace std;

const int N = 505, mod = 998244353;

int n;
struct edge
{
    int to, next;
}e[N << 1];
int head[N], cnt;
int g[N];
int siz[N];
int son[N];
int f[N][N];
int h[N][N];
int jc[N];

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

void add(int u, int v)
{
    e[++ cnt] = {v, head[u]};
    head[u] = cnt;
}

void dfs1(int u, int ff)
{
    siz[u] = 1;
    son[u] = 0;
    g[u] = 1;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == ff) continue;
        dfs1(v, u);
        siz[u] += siz[v];
        son[u] ++;
        g[u] = 1LL * g[u] * g[v] % mod;
    }
    g[u] = 1LL * g[u] * jc[son[u]] % mod;
}

void dfs2(int u, int ff)
{
    if (ff)
    {
        int cnt = 0;
        for (int i = head[ff]; i; i = e[i].next)
        {
            int v = e[i].to;
            if (v == u) continue;
            cnt ++;
            for (int j = 0; j <= n; j ++ )
            {
                h[cnt][j] = h[cnt - 1][j];
                if (j >= siz[v]) h[cnt][j] = (h[cnt][j] + 1LL * h[cnt - 1][j - siz[v]] * g[v] % mod) % mod;
            }
        }
        for (int i = 1; i <= n; i ++ )
            for (int j = 0; j <= n; j ++ )
                f[u][i + j + 1] = (f[u][i + j + 1] + 1LL * f[ff][i] * h[cnt][j] % mod) % mod;
    }
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == ff) continue;
        dfs2(v, u);
    }
}   

int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i ++ )
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }
    jc[0] = 1;
    for (int i = 1; i <= n; i ++ )
        jc[i] = 1LL * jc[i - 1] * i % mod;

    dfs1(1, 0);

    f[1][1] = 1LL * g[1] * qpow(jc[siz[1]], mod - 2) % mod;
    h[0][0] = 1;
    dfs2(1, 0);

    for (int i = 1; i <= n; i ++ )
    {
        for (int j = 1; j <= n; j ++ )
            printf("%d ", 1LL * f[i][j] * jc[siz[i]] % mod);
        puts("");
    }

    return 0;
}