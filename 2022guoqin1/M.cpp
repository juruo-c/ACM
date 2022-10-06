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

const int N = 1000005;

int tot;
int a[N];

struct edge
{
    int to, next;
}e[N << 1], e2[N << 1];
int head[N], cnt;
int head2[N], cnt2;
int dfn[N], low[N];
int stack[N], ins[N], c[N];
vector<int> scc[N];
int num, top, scc_cnt;
int in[N], etr[N];
int ans[N];

void add(int u, int v)
{
    e[++ cnt] = {v, head[u]};
    head[u] = cnt;
}

void add2(int u, int v)
{
    e2[++ cnt2] = {v, head2[u]};
    head2[u] = cnt2;
}

void tarjan(int u)
{
    dfn[u] = low[u] = ++ num;
    stack[++ top] = u, ins[u] = 1;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(ins[v])
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u])
    {
        scc_cnt ++;int y;
        do 
        {
            y = stack[top --], ins[y] = 0;
            c[y] = scc_cnt, scc[scc_cnt].push_back(y);
        }while(u != y);
    }
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int n, m;
    scanf("%d%d", &n, &m);

    int t = 0;
    for (int i = 1; i <= m; i ++ )
        for (int j = 1; j <= n; j ++ )
        {
            scanf("%d", &a[++ t]);
            if (j != 1)
                add(a[t], a[t - 1]);
        }
    for (int i = 1; i <= n; i ++ )
        if (!dfn[i])
            tarjan(i);
    // printf("%d\n", scc_cnt);
    set<PII> s;
    for (int u = 1; u <= n; u ++ )
    {
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].to;
            PII t = make_pair(c[u], c[v]);
            if (c[v] == c[u] || s.count(t)) continue;
            s.insert(t);
            add2(c[u], c[v]), in[c[v]] ++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= scc_cnt; i ++ )
        if (!in[i]) q.push(i);
    
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = head2[u]; i; i = e2[i].next)
        {
            int v = e2[i].to;
            in[v] --;
            etr[v] += scc[u].size() + etr[u];
            if (!in[v])
                q.push(v);
        }
    }

    for (int i = 1; i <= scc_cnt; i ++ )
    {
        int sz = scc[i].size();
        for (int j = 0; j < sz; j ++ )
        {
            int u = scc[i][j];
            ans[u] = sz - 1 + etr[i];
        }
    }

    for (int i = 1; i <= n; i ++ )
        printf("%d ", ans[i]);

    return 0;
}
