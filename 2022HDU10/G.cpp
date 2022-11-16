#include <bits/stdc++.h>

using namespace std;

const int N = 100005, mod = 998244353;

struct edge
{
    int to, next;
}e[N << 1];
int head[N], cnt;
int siz[N];
int ans;

void add(int u, int v)
{
    e[++ cnt] = {v, head[u]};
    head[u] = cnt;
}

void dfs(int u, int ff)
{
    siz[u] = 1;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == ff) continue;
        dfs(v, u);
        if (siz[v] % 2) siz[u] += siz[v];
        else ans = ans * 2 % mod;
    }
}

int main ()
{
    int _;
    scanf("%d", &_);
    while (_ --)
    {
        int n;
        scanf("%d", &n);
        
        cnt = 0;
        for (int i = 1; i <= n; i ++ ) head[i] = 0;

        for (int i = 1; i < n; i ++ )
        {
            int u, v;
            scanf("%d%d", &u, &v);
            add(u, v);
            add(v, u);
        }

        ans = 1;
        dfs(1, 0);
        printf("%d\n", (ans - 1 + mod) % mod);
    }
    return 0;
}