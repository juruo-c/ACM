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

int n;
int a[N];
struct edge
{
    int to, next;
}e[N << 1];
int head[N], tot;
int cnt[1 << 20][20][2];
int siz[N], son[N];
bool vis[N];
LL ans;

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

void modify(int u, int ff, int val)
{
    for (int i = 0; i < 20; i ++ )
        cnt[a[u]][i][u >> i & 1] += val;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == ff) continue;
        modify(v, u, val);
    }
}

void updateAns(int u, int ff, int lca)
{
    int x = a[u] ^ a[lca];
    for (int i = 0; i < 20; i ++ )
        ans += (1LL << i) * cnt[x][i][u >> i & 1 ^ 1];
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == ff) continue;
        updateAns(v, u, lca);
    }
}

void dfs2(int u, int ff, int keep)
{
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == ff || son[u] == v) continue;
        dfs2(v, u, 0);
    }
    if (son[u]) dfs2(son[u], u, 1), vis[son[u]] = true;
    
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == ff || vis[v]) continue;
        updateAns(v, u, u);
        modify(v, u, 1);
    }
    for (int i = 0; i < 20; i ++ )
        cnt[a[u]][i][u >> i & 1] ++;
    vis[son[u]] = false;

    if (!keep)
        modify(u, ff, -1);
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ )
        scanf("%d", &a[i]);
    for (int i = 1; i < n; i ++ )
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }

    dfs(1, 0);
    dfs2(1, 0, 0);

    printf("%lld\n", ans);

    return 0;
}
