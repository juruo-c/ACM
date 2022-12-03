#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

typedef long long LL;

int n, m, q;
struct edge
{
    int to, next, w;
}e[N << 1];
int head[N], tot;
int fa[N];
bool isLoop[N];
bool vis[N];
int siz[N], cnt[N];
LL dis[N];

void add(int u, int v, int w)
{
    e[++ tot] = {v, head[u], w};
    head[u] = tot;
}

int getf(int x)
{
    return x == fa[x] ? x : fa[x] = getf(fa[x]);
}

bool spfa(int s)
{
    queue<int> q;
    q.push(s);
    vis[s] = true;
    dis[s] = 0;
    while (!q.empty())
    {
        int u = q.front();q.pop();
        vis[u] = false;
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].to;
            if (dis[v] > dis[u] + e[i].w)
            {
                dis[v] = dis[u] + e[i].w;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= siz[s]) return true;
                if (!vis[v])
                {
                    q.push(v);
                    vis[v] = true;
                }
            }

        }
    }
    return false;
}

void dfs(int x, LL d)
{
    dis[x] = d;
    for (int i = head[x]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (dis[v] == 1e18)
            dfs(v, d + e[i].w);
        else if (dis[v] != d + e[i].w)
            isLoop[getf(v)] = true;
    }   
}

int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i ++ ) fa[i] = i;
    for (int i = 1; i <= m; i ++ )
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
        add(v, u, -w);
        u = getf(u), v = getf(v);
        if (u != v)
            fa[u] = v;
    }

    set<int> s;
    for (int i = 1; i <= n; i ++ )
        s.insert(getf(i)), siz[getf(i)] ++;
    
    for (int i = 1; i <= n; i ++ ) dis[i] = 1e18;

    for (auto x : s)
        dfs(x, 0);

    for (int i = 1; i <= q; i ++ )
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (getf(x) != getf(y)) puts("nan");
        else if(isLoop[getf(x)]) puts("inf");
        else 
        {
            printf("%lld\n", dis[y] - dis[x]);
        }
    }

    return 0;
}