#include <bits/stdc++.h>

using namespace std;

const int N = 505, mod = 998244353;

int n;
vector<int> e[N];
int head[N], cnt;
int g[N];
int siz[N];
int son[N];
int f[N][N];
int h[N][N][N];
int tmp[N];
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

void dfs1(int u, int ff)
{
    siz[u] = 1;
    son[u] = 0;
    g[u] = 1;
    for (auto v : e[u])
    {
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
    int sz = 0;
    int G = 1;
    for (auto v : e[u])
    {
        if (v == ff) continue;
        sz ++;
        G = 1LL * G * g[v] % mod;
        for (int j = 0; j <= sz; j ++ )
            for (int k = 0; k <= n; k ++ )
            {
                h[sz][j][k] = h[sz - 1][j][k];
                if (j && k >= siz[v]) h[sz][j][k] = (h[sz][j][k] + h[sz - 1][j - 1][k - siz[v]]) % mod;
            }
    }

    for (auto v : e[u])
    {
        if (v == ff) continue;
        G = 1LL * G * qpow(g[v], mod - 2) % mod;

        for (int j = 1; j <= sz; j ++ )
            for (int k = siz[v]; k <= n; k ++ ) 
                h[sz][j][k] = (h[sz][j][k] - h[sz][j - 1][k - siz[v]] + mod) % mod;

        for (int i = 0; i <= n; i ++ ) tmp[i] = 0;
        for (int j = 0; j <= sz - 1; j ++ )
            for (int k = 0; k <= n; k ++ )
                tmp[k] = (tmp[k] + 1LL * h[sz][j][k] * jc[j] % mod * jc[sz - 1 - j] % mod) % mod;

        for (int j = 1; j <= n; j ++ )
            for (int k = 0; k <= n; k ++ )
                if (j + k + 1 <= n)
                    f[v][j + k + 1] = (f[v][j + k + 1] + 1LL * f[u][j] * tmp[k] % mod * G % mod) % mod;

        for (int j = sz; j >= 1; j -- )
            for (int k = n; k >= siz[v]; k -- )
                h[sz][j][k] = (h[sz][j][k] + h[sz][j - 1][k - siz[v]]) % mod;

        G = 1LL * G * g[v] % mod;
    }
    
    for (auto v : e[u])
    {
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
        e[u].push_back(v);
        e[v].push_back(u);
    }
    jc[0] = 1;
    for (int i = 1; i <= n; i ++ )
        jc[i] = 1LL * jc[i - 1] * i % mod;

    dfs1(1, 0);

    f[1][1] = 1;
    h[0][0][0] = 1;
    dfs2(1, 0);

    for (int i = 1; i <= n; i ++ )
    {
        for (int j = 1; j <= n; j ++ )
            printf("%d ", 1LL * f[i][j] * g[i] % mod);
        puts("");
    }

    return 0;
}

/*
5
1 2
1 3
3 4
3 5
*/