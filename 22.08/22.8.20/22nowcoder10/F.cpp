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

const int N = 105, M = 10005;

int n, m, s, t;
struct edge
{
    int to, next;
}e[M << 1];
int head[N], cnt;
int d[N];

void add(int u, int v)
{
    e[++ cnt] = {v, head[u]};
    head[u] = cnt;
}

void bfs()
{
    queue<int> q;
    q.push(t);
    d[t] = 2;
    
    while (!q.empty())
    {
        int u = q.front(); q.pop();

        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].to;
            if (++ d[v] == 2)
                q.push(v);
        }
    }
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int _; scanf("%d", &_);
    while (_ --)
    {
        scanf("%d%d%d%d", &n, &m, &s, &t);
        cnt = 0;
        for (int i = 1; i <= n; i ++ ) head[i] = d[i] = 0;
    
        for (int i = 1; i <= m; i ++ ) 
        {
            int u, v;
            scanf("%d%d", &u, &v);
            add(u, v);
            add(v, u);
        }

        bfs();

        if (d[s] >= 2) puts("Join Player");
        else puts("Cut Player");

    }
    return 0;
}
