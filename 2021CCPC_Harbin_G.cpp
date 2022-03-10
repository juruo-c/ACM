#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 100005, M = 1 << 20, INF = 0x3f3f3f3f;

int t, r, n, m, k;
struct edge
{
    int to, next, w;
}e[N << 1];
int head[N], cnt;
vector<PII> key;
double f[M][20];
int dis[20][20];
int d[N];
bool vis[N];

void add(int u, int v, int w)
{
    e[++ cnt] = {v, head[u], w};
    head[u] = cnt;
}

void dijkstra(int s)
{
    for (int i = 1; i <= n; i ++ ) d[i] = INF, vis[i] = false;

    priority_queue<PII, vector<PII>, greater<PII> > q;
    q.push({0, s});
    d[s] = 0;

    while (!q.empty())
    {
        auto t = q.top();
        q.pop();

        int u = t.second;
        if (vis[u]) continue;
        vis[u] = true;

        for (int i = head[u]; i; i = e[i].next )
        {
            int v = e[i].to;
            int w = e[i].w;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                if (!vis[v])
                    q.push({d[v], v});
            }
        }
    }

}

int main()
{
    scanf("%d%d%d%d", &t, &r, &n, &m);
    for (int i = 1; i <= m; i ++ )
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i ++ )
    {
        int a, p;
        scanf("%d%d", &a, &p);
        key.push_back({a, p});
    }

    sort(key.begin(), key.end());
    if (key[0].first != 1) key.push_back({1, 0});
    if (key.back().first != n) key.push_back({n, 0});

    for (int i = 0; i < key.size(); i ++ )
    {
        int u = key[i].first;
        dijkstra(u);
        for (int j = 0; j < key.size(); j ++ )
        {
            int v = key[j].first;
            dis[i][j] = d[v];
        }
    }

    if (dis[k][k + 1] == INF)
    {
        puts("-1");
        return 0;
    }

    for (int S = (1 << k) - 1; S >= 0; S -- )
    {
        for (int i = 0; i < k; i ++ )
            if (S & (1 << i))
            {
                double p = key[i].second * 0.01;
                double t1 = (1 - p) * dis[i][k + 1] / r;
                double t2 = 1.0 * dis[i][k + 1] / t;
                for (int j = 0; j < k; j ++ )
                    if ((S & (1 << j)) == 0)
                        t2 = min(t2, 1.0 * dis[i][j] / t + f[S | (1 << j)][j]);
                f[S][i] = t1 + t2 * p;
            }
    }

    double ans = 1.0 * dis[k][k + 1] / t;
    for (int j = 0; j < k; j ++ )
        ans = min(ans, 1.0 * dis[k][j] / t + f[(1 << j)][j]);
    printf("%.10f\n", ans);

    return 0;
}
