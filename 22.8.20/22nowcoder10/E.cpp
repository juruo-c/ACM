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

const int INF = 1 << 29, N = 805, M = 200005;

struct edge
{
    int to, next, w;
}e[M << 1];
int head[N], cnt, d[N], now[N];

int n, m, s, t;
int ans[N];
char str[N][N];

queue<int> q;

void add(int u, int v, int w)
{
    e[++ cnt] = {v, head[u], w};
    head[u] = cnt;
    e[++ cnt] = {u, head[v], 0};
    head[v] = cnt;
}

bool bfs()
{
    memset(d, 0, sizeof d);
    while (q.size()) q.pop();
    q.push(s);
    d[s] = 1;
    now[s] = head[s];
    while (q.size())
    {
        int u = q.front();q.pop();
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].to, w = e[i].w;
            if (w && !d[v])
            {
                q.push(v);
                now[v] = head[v];
                d[v] = d[u] + 1;
                if (v == t) return true;
            }
        }
    }
    return false;
}

int dfs(int x, int flow)
{
    if (x == t) return flow;
    int rest = flow, k;
    for (int i = now[x]; i && rest; i = e[i].next)
    {
        now[x] = i;
        int v = e[i].to, w = e[i].w;
        if (w && d[v] == d[x] + 1)
        {
            k = dfs(v, min(rest, w));
            if (!k) d[v] = 0;
            e[i].w -= k;
            e[i ^ 1].w += k;
            rest -= k;
        }
    }
    return flow - rest;
}

int dinic()
{
    int flow = 0, mxflow = 0;
    while (bfs())
        while(flow = dfs(s, INF)) mxflow += flow;
    return mxflow;
}

void add_edge()
{
    for (int i = 2; i <= cnt; i ++ ) head[i] = 0;
    cnt = 1;
    for (int i = 1; i <= n; i ++ ) 
        if (!ans[i])
        {
            add(s, i, 1);
            for (int j = 1; j <= m; j ++ )
                if (str[i][j] == '1') add(i, j + n, 1);
        }
    for (int i = 1; i <= m; i ++ ) add(i + n, t, 1);
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif

    scanf("%d%d", &n, &m);
    s = 0, t = n + m + 1;

    bool flag = true;
    for (int i = 1; i <= n; i ++ )
    {
        scanf("%s", str[i] + 1);
        bool ff = false;
        for (int j = 1; j <= m; j ++ )
            if (str[i][j] == '1') ff = true;
        if (!ff) flag = false;
    }

    if (!flag)
    {
        puts("-1");
        return 0;
    }
    
    int match = 0;
    while (match < n)
    {
        match += dinic();
        for (int i = 1; i <= n; i ++ )
            if (!ans[i])
            {    
                for (int j = head[i]; j; j = e[i].next)
                {
                    int v = e[i].to;
                    if (v > n && !e[i].w)
                        ans[i] = v - n;
                }
            }
    }

    for (int i = 1; i <= n; i ++ ) printf("%d ", ans[i]);

    return 0;
}
