#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#define ZYCMH

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100005, mod = 1000000007;

int n, k;
int x[N];
int a[N], b[N];
struct edge
{
    int to, next;
}e1[N << 1], e2[N << 1];
int h1[N], cnt1, h2[N], cnt2;
int d1[N], f1[N][20], d2[N], f2[N][20];
bool flag[N];
int siz1[N], siz2[N];
int id1[N], id2[N];

void add1(int u, int v)
{
    e1[++ cnt1] = {v, h1[u]};
    h1[u] = cnt1;
}

void add2(int u, int v)
{
    e2[++ cnt2] = {v, h2[u]};
    h2[u] = cnt2;
}

void bfs(int d[], int f[][20], int head[], edge e[])
{
    queue<int> q;
    q.push(1);
    d[1] = 1;
    while (q.size())
    {
        int u = q.front(); q.pop();
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].to;
            if (d[v]) continue;
            d[v] = d[u] + 1;
            f[v][0] = u;
            for (int j = 1; j < 20; j ++ )
                f[v][j] = f[f[v][j - 1]][j - 1];
            q.push(v);            
        }
    }
}

int LCA(int x, int y, int f[][20], int d[])
{
    if (d[x] > d[y]) swap(x, y);
    for (int i = 19; i >= 0; i -- )
        if (d[f[y][i]] >= d[x]) y = f[y][i];
    if (x == y) return x;
    for (int i = 19; i >= 0; i -- )
    {
        if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
    }
    return f[x][0];
}

void dfs(int u, int siz[], int h[], edge e[], int id[])
{
    if (flag[u]) siz[u] ++, id[u] = u;
    for (int i = h[u]; i; i = e[i].next)
    {   
        int v = e[i].to;
        dfs(v, siz, h, e, id);
        siz[u] += siz[v];
        if (id[v])
            id[u] = id[v];
    }
}

int LCA_exclude(int u, int f[][20], int d[])
{
    int l;
    if (x[1] != u) l = x[1];
    else l = x[2];
    for (int i = 1; i <= k; i ++ )
        if (x[i] != u)
            l = LCA(l, x[i], f, d);
    return l;
}

int calc(int u, int lca, int siz[], int val[], int head[], edge e[], int son, int f[][20], int d[], int id[])
{
    if (flag[lca])
    {
        if (u == lca && son == 1) 
        {
            return val[LCA_exclude(u, f, d)];
        }
        else return val[lca];
    }
    else
    {
        if (son >= 3) return val[lca];
        else if (son == 2)
        {
            vector<int> vec;
            for (int i = head[lca]; i; i = e[i].next)
            {
                int v = e[i].to;
                if (siz[v] == 1) vec.push_back(v);
            }
            for (int i = 0; i < vec.size(); i ++ )
            {
                if (u == id[vec[i]])
                {
                    return val[LCA_exclude(u, f, d)];
                }
            }
            return val[lca];
        }
    }
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int t = 1;
    while (t --)
    {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= k; i ++ )
            scanf("%d", &x[i]), flag[x[i]] = true;
        for (int i = 1; i <= n; i ++ )
            scanf("%d", &a[i]);
        for (int i = 2; i <= n; i ++ )
        {
            int p;scanf("%d", &p);
            add1(p, i);
        }
        for (int i = 1; i <= n; i ++ )
            scanf("%d", &b[i]);
        for (int i = 2; i <= n; i ++ )
        {
            int p;scanf("%d", &p);
            add2(p, i);
        }

        bfs(d1, f1, h1, e1);
        bfs(d2, f2, h2, e2);

        int lca1 = x[1], lca2 = x[1];
        for (int i = 2; i <= k; i ++ )
            lca1 = LCA(lca1, x[i], f1, d1), lca2 = LCA(lca2, x[i], f2, d2);

        dfs(1, siz1, h1, e1, id1);
        dfs(1, siz2, h2, e2, id2);

        int c1 = 0, c2 = 0;
        for (int i = h1[lca1]; i; i = e1[i].next)
        {
            int v = e1[i].to;
            if (siz1[v]) c1 ++;
        }
        for (int i = h2[lca2]; i; i = e2[i].next)
        {
            int v = e2[i].to;
            if (siz2[v]) c2 ++;
        }

        int ans = 0;
        for (int i = 1; i <= k; i ++ )
        {
            int t1 = calc(x[i], lca1, siz1, a, h1, e1, c1, f1, d1, id1);
            int t2 = calc(x[i], lca2, siz2, b, h2, e2, c2, f2, d2, id2);
            // cout << "x[i] = " << x[i] << endl;
            // cout << "t1 = " << t1 << endl;
            // cout << "t2 = " << t2 << endl;
            ans += (t1 > t2);
        }

        printf("%d\n", ans);

    }
    return 0;
}
