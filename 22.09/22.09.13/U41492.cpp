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

const int N = 100005;

int n, q;
int c[N], ans[N];
int siz[N], son[N], cnt[N], top;

struct edge
{
    int to, next;
}e[N << 1];
int head[N], tot;
bool vis[N];

void add(int u, int v)
{
    e[++ tot] = {v, head[u]};
    head[u] = tot;
}

void dfs(int u, int ff)
{
    siz[u] = 1;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == ff) continue;
        dfs(v, u);
        siz[u] += siz[v];
        if (!son[u] || siz[v] > siz[son[u]]) son[u] = v;
    }
}

void calc(int u, int ff, int k)
{
    if (k > 0)
    {
        if (!cnt[c[u]]) top ++;
        cnt[c[u]] ++;
    }
    else 
    {
        if (cnt[c[u]] <= 1) top --;
        cnt[c[u]] --;
    }
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == ff || vis[v]) continue;
        calc(v, u, k);
    }
}

void dfs2(int u, int ff, int keep)
{
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == ff || v == son[u]) continue;
        dfs2(v, u, 0);
    }
    if (son[u]) dfs2(son[u], u, 1), vis[son[u]] = true;
    calc(u, ff, 1);
    vis[son[u]] = false;
    ans[u] = top;
    if (!keep) calc(u, ff, -1);
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    scanf("%d", &n);
    for (int i = 1; i < n; i ++ )
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }
    for (int i = 1; i <= n; i ++ ) scanf("%d", &c[i]);
    dfs(1, 0);
    dfs2(1, 0, 0);
    scanf("%d", &q);
    while (q --)
    {
        int x;
        scanf("%d", &x);
        printf("%d\n", ans[x]);
    }
    return 0;
}
