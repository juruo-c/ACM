#include <bits/stdc++.h>

using namespace std;

const int N = 500005;

int n;
struct edge
{
    int to, next;
}e[N << 1];
int head[N], cnt;
int idx;
int val[N];
map<int, int> id;
bool vis[N];
int ans = 1;

void add(int u, int v)
{
    e[++ cnt] = {v, head[u]};
    head[u] = cnt;
}

void dfs(int u)
{
    ans = max(ans, val[u]);
    vis[u] = true;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (!vis[v]) dfs(v);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ )
    {
        int u, v;
        scanf("%d%d", &u, &v);
        if (!id[u]) id[u] = ++ idx, val[idx] = u;
        if (!id[v]) id[v] = ++ idx, val[idx] = v;
        u = id[u], v = id[v];
        add(u, v);
        add(v, u);
    }

    if (!id[1]) puts("1");
    else 
    {
        dfs(id[1]);
        printf("%d\n", ans);
    }

    return 0;
}