#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int N = 100005, M = 1 << 20, INF = 0x3f3f3f3f;

double t, r;
int n, m, k;
struct edge
{
    int to, next, w;
}e[N << 1];
int head[N], cnt;
int a[20];
double p[20];
double f[20][M];
int dist[20][20];
int id[N];

void add(int u, int v, int w)
{
    e[++ cnt] = {v, head[u], w};
    head[u] = cnt;
}

int dis[N];
bool vis[N];
struct Node
{
    int s, d;
    bool operator < (const Node& b) const 
    {
        return b.d < d;
    }
};

void dij(int s)
{
    // cout << "s = " << s << " id = " << id[s] << endl;
    for (int i = 1; i <= n; i ++ ) vis[i] = false, dis[i] = INF;
    priority_queue<Node> q;
    dis[s] = 0;
    q.push({s, 0});
    while (q.size())
    {
        int u = q.top().s;
        q.pop();

        if (vis[u]) continue;
        vis[u] = true;

        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].to;
            if ( vis[v] ) continue;
            if (dis[v] > dis[u] + e[i].w)
            {
                dis[v] = dis[u] + e[i].w;
                q.push({v, dis[v]});
            }
        }
    }
    // for (int i = 0; i < k; i ++ )
        // cout << "a[i] = " << a[i] << " dis[a[i]] = " << dis[a[i]] << endl;
    for (int i = 0; i < k; i ++ )
        dist[id[s]][i] = dis[a[i]];
}


int main()
{
    scanf("%lf%lf", &t, &r);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i ++ )
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
    }

    scanf("%d", &k);
    for (int i = 1; i <= n; i ++ ) id[i] = -1;
    for (int i = 0; i < k; i ++ )
    {
        scanf("%d%lf", &a[i], &p[i]), p[i] /= 100;
        id[a[i]] = i;
    }

    if (id[1] == -1) a[k] = 1, p[k] = 1, id[1] = k ++;
    if (id[n] == -1) a[k] = n, p[k] = 1, id[n] = k ++;

    for (int i = 0; i < k; i ++ )
        dij(a[i]);

    // for (int i = 0; i < k; i ++ )
    // {
    //     for (int j = 0; j < k; j ++ )
    //         cout << dist[i][j] << " ";
    //     cout << endl;
    // }

    // for (int i = 0; i < k; i ++ )
    //     cout << "i = " << i << " a[i] = " << a[i] << endl;
    if (dist[id[1]][id[n]] == INF) 
    {
        puts("-1");
        return 0;
    }

    for (int j = (1 << k) - 1; j >= 0; j -- )
    {
        if (j >> id[n] & 1) continue;
        for (int i = 0; i < k; i ++ )
        {
            if (i == id[n] || (j >> i & 1)) continue;
            double mi = 1e18;
            for (int s = 0; s < k; s ++ )
            {
                if (s == i || (j >> s & 1)) continue;
                mi = min(mi, dist[i][s] / t + f[s][j | (1 << i)]);
            }
            f[i][j] = p[i] * mi + (1.0 - p[i]) * dist[i][id[n]] / r;
        }
    }

    printf("%.10f\n", f[id[1]][0]);

    return 0;
}