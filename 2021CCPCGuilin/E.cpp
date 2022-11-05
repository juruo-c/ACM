#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
typedef long long LL;

const int N = 2005, M = 5005;


int n, m, c;

struct edge
{
    int to, next, w;
}e[M];
int head[N], cnt;
LL dis[N];
bool vis[N];
LL dist[N][N];

void add(int u, int v, int w)
{
    e[++ cnt] = {v, head[u], w};
    head[u] = cnt;
}

struct Node
{
    int s;
    LL d;
    bool operator < (const Node& b) const 
    {
        return d > b.d;
    }
};

void dij(int s)
{
    for (int i = 1; i <= n; i ++ ) dis[i] = 1e18, vis[i] = false;
    dis[s] = 0;
    priority_queue<Node> q;
    q.push({s, 0});
    while (!q.empty())
    {
        int u = q.top().s;
        q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].to;
            if (vis[v]) continue;
            if (dis[v] > dis[u] + e[i].w)
            {
                dis[v] = dis[u] + e[i].w;
                q.push({v, dis[v]});
            }
        }
    }

    for (int i = 1; i <= n; i ++ )
        dist[s][i] = dis[i];

}

int main()
{
    scanf("%d%d%d", &n, &m, &c);
    bool flag = false;
    for (int i = 1; i <= m; i ++ )
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
        if (c >= w) flag = true;
    }

    if (!flag)
    {
        puts("0");
        return 0;
    }

    for (int i = 1; i <= n; i ++ )
        dij(i);

    LL ans = 1e18;
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            if (i != j)
                ans = min(ans, dist[i][j] + dist[j][i]);

    if (ans <= c) puts("2");
    else puts("1");


    return 0;
}