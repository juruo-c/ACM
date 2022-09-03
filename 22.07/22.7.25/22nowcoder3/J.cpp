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

const int N = 2000005, mod = 1000000007, INF = 0x3f3f3f3f;

int n;
int c[N][5];
int tot;
map<PII, int> ma;
vector<PII> edge;

struct Edge
{
    int to, next, w;
}e[N * 4];
int head[N], cnt;
int dis[N];
bool vis[N];

void add(int u, int v, int w)
{
    e[++ cnt] = {v, head[u], w};
    head[u] = cnt;
}

int findid(int u, int v)
{
    for (int i = 1; i <= 4; i ++ )
        if (v == c[u][i])
            return i;
    return 0;
}

struct Node
{
    int d, s;
    bool operator < (const Node & b) const
    {
        return d > b.d;
    }
};

int dij(int s, int ed)
{
    for (int i = 1; i <= tot; i ++ ) dis[i] = INF, vis[i] = false;
    priority_queue<Node> q;
    q.push({0, s});
    dis[s] = 0;
    
    while (!q.empty())
    {
        int u = q.top().s;
        q.pop();
        if (vis[u]) continue;
        vis[u] = true;

        if (u == ed) break;

        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].to;
            int w = e[i].w;
            if (vis[v]) continue;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                q.push((Node){dis[v], v});
            }
        }
    }

    return dis[ed];
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
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++ )
        {
            scanf("%d%d%d%d", &c[i][1], &c[i][2], &c[i][3], &c[i][4]);
            for (int j = 1; j <= 4; j ++ )
            {
                if (c[i][j])
                {
                    PII t = make_pair(i, c[i][j]);
                    edge.push_back(t);
                    ma[t] = ++ tot;
                }
            }

        }

        // for (int i = 0; i < edge.size(); i ++ )
        //     cout << edge[i].first << " " << edge[i].second << " " << ma[edge[i]] << endl;
                
        for (int i = 0; i < edge.size(); i ++ )
        {
            PII e = edge[i];
            int u = e.first, v = e.second;
            int uid = findid(v, u);
            for (int j = 1; j <= 4; j ++ )
                if (c[v][j])
                {
                    PII t = make_pair(v, c[v][j]);
                    if (uid % 4 + 1 == j) add(ma[e], ma[t], 0);
                    else add(ma[e], ma[t], 1);
                }
        }

        int stS, stD, edS, edD;
        scanf("%d%d%d%d", &stS, &stD, &edS, &edD);

        PII st = make_pair(stS, stD), ed = make_pair(edS, edD);
        int ans = dij(ma[st], ma[ed]);
        
        if (ans == INF) puts("-1");
        else printf("%d\n", ans);

    }
    return 0;
}
