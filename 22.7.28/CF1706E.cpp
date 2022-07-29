#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 200005, mod = 1000000007;

int n, m, q;
struct Edge
{
    int u, v, w;
    bool operator < (const Edge& b) const
    {
        return w < b.w;
    }
}E[N];
struct edge
{
    int to, next, w;
}e[N << 1];
int head[N], cnt;
int st[N][20], lg[N];
int fa[N];
int f[N][20], dep[N], mx[N][20];

int getf(int x)
{
    return x == fa[x] ? x : fa[x] = getf(fa[x]);
}

void add(int u, int v, int w)
{
    e[++ cnt] = {v, head[u], w};
    head[u] = cnt;
}

void Kruskal()
{
    sort(E + 1, E + 1 + m);
    for (int i = 1; i <= m; i ++ )
    {
        int u = getf(E[i].u), v = getf(E[i].v);
        if (u != v)
        {
            fa[u] = v;
            add(u, v, E[i].w);
            add(v, u, E[i].w);
        }
    }
}

void dfs(int u, int ff, int fw)
{
    f[u][0] = ff, mx[u][0] = fw;
    dep[u] = dep[ff] + 1;
    for (int i = 1; i < 20; i ++ )
        f[u][i] = f[f[u][i - 1]][i - 1];
    for (int i = 1; i < 20; i ++ )
        mx[u][i] = max(mx[u][i - 1], mx[f[u][i - 1]][i - 1]);

    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to, w = e[i].w;
        if (v == ff) continue;
        dfs(v, u, w);
    }
}

int LCA(int x, int y)
{
    int res = 0;
    if (dep[x] < dep[y]) swap(x, y);
    for (int i = 19; i >= 0; i -- )
        if (dep[f[x][i]] >= dep[y])
        {
            res = max(res, mx[x][i]);
            x = f[x][i];
        }
    if (x == y) return res;
    for (int i = 19; i >= 0; i -- )
        if (f[x][i] != f[y][i])
        {
            res = max(res, mx[x][i]);
            res = max(res, mx[y][i]);
            x = f[x][i], y = f[y][i];
        }
    return max(max(res, mx[x][0]), mx[y][0]);
}

void st_init()
{
    for (int i = 2; i <= n; i ++ )
        lg[i] = lg[i >> 1] + 1;
    for (int j = 1; j < 20; j ++ )
        for (int i = 1; i + (1 << j) - 1 <= n; i ++ )
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

int st_query(int l, int r)
{
    int k = lg[(r - l + 1)];
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int t; scanf("%d", &t);
    while (t --)
    {
        cnt = 0;

        scanf("%d%d%d", &n, &m, &q);
        for (int i = 1; i <= n; i ++ )
            head[i] = dep[i] = 0;
        for (int i = 1; i <= n; i ++) fa[i] = i;
        for (int i = 1; i <= m; i ++)
            scanf("%d%d", &E[i].u, &E[i].v), E[i].w = i;
        
        Kruskal();

        dfs(1, 0, 0);

        // for (int i = 1; i <= n; i ++ )
        //     printf("mx[%d][0] = %d\n", i, mx[i][0]);

        for (int i = 2; i <= n; i ++ )
        {
            st[i][0] = LCA(i - 1, i);
            // printf("st[%d][0] = %d\n", i, st[i][0]);
        }


        st_init();

        for (int i = 1; i <= q; i ++ )
        {
            int l, r;
            scanf("%d%d", &l, &r);
            if (i > 1) printf(" ");
            if (l == r) printf("0");
            else printf("%d", st_query(l + 1, r));
        }
        puts("");

    }
    return 0;
}
