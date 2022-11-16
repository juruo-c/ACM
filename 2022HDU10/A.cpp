#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f, N = 50010, M = 300010;

struct edge
{
    int to, next, w;
}e[M];
struct Edge
{
    int u, v;
}E[M];
int head[N], cnt;
int d[N], now[M];
int win[N];

int n, m1, m2, s, t;

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
    d[s] = 1; now[s] = head[s];
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].to;
            if (e[i].w && !d[v])
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

int dfs(int u, int flow)
{
    if (u == t) return flow;
    int rest = flow, k, i;
    for (i = now[u]; i && rest; i = e[i].next)
    {
        int v = e[i].to;
        if (e[i].w && d[v] == d[u] + 1)
        {
            k = dfs(v, min(rest, e[i].w));
            if (!k) d[v] = 0;
            e[i].w -= k;
            e[i ^ 1].w += k;
            rest -= k;
        }
    }
    now[u] = i;
    return flow - rest;
}

int dinic()
{
    int flow = 0, mxflow = 0;
    while (bfs())
        while (flow = dfs(s, INF)) mxflow += flow;
    return mxflow;
}

int main()
{
    int _;
    scanf("%d", &_);
    while (_ --)
    {
        memset(head, 0, sizeof head);
        memset(win, 0, sizeof win);
        cnt = 1;
        scanf("%d%d%d", &n, &m1, &m2);
        for (int i = 1; i <= m1; i ++ )
        {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            if (z) win[x] ++;
            else win[y] ++;
        }
        int m = 0;
        for (int i = 1; i <= m2; i ++ )
        {
            scanf("%d%d", &E[i].u, &E[i].v);
            if (E[i].u == 1 || E[i].v == 1)
                win[1] ++;
            else m ++;
        }

        bool flag = false;
        for (int i = 2; i <= n; i ++ )
            if (win[i] > win[1])
            {
                flag = true;
                break;
            }

        if (flag)
        {
            puts("NO");
            continue;
        }

        s = 0, t = n + m2 + 1;
        for (int i = 2; i <= n; i ++ )
            add(s, i, win[1] - win[i]);
        for (int i = 1; i <= m2; i ++ )
            if (E[i].u != 1 && E[i].v != 1)
                add(E[i].u, i + n, 1), add(E[i].v, i + n, 1), add(i + n, t, 1);
        
        if (dinic() < m) puts("NO");
        else puts("YES");

    }
    return 0;
}