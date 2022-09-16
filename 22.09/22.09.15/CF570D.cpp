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

const int N = 500005;

char c[N];

struct edge
{
    int to, next;
}e[N << 1];
struct Node
{
    int id, d;
};
int head[N], tot;
vector<Node> query[N];
int siz[N], dep[N], son[N];
int cnt[N][26];
bool vis[N];
int ans[N];

void add(int u, int v)
{
    e[++ tot] = {v, head[u]};
    head[u] = tot;
}

void dfs(int u, int ff)
{
    siz[u] = 1;
    dep[u] = dep[ff] + 1;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        dfs(v, u);
        siz[u] += siz[v];
        if (!son[u] || siz[v] > siz[son[u]]) son[u] = v;
    }
}

void calc(int u, int val)
{
    cnt[dep[u]][c[u] - 'a'] += val;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (vis[v]) continue;
        calc(v, val);
    }
}

bool ask(int x)
{
    int res = 0;
    for (int i = 0; i < 26; i ++ )
    {
        if (cnt[x][i] % 2) res ++;
    }
    return res <= 1;
}

void dfs2(int u, int keep)
{
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == son[u]) continue;
        dfs2(v, 0);
    }
    if (son[u]) dfs2(son[u], 1), vis[son[u]] = true;
    calc(u, 1), vis[son[u]] = false;
    int sz = query[u].size();
    for (int i = 0; i < sz; i ++ ) ans[query[u][i].id] = ask(query[u][i].d);
    if (!keep) calc(u, -1);
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 2; i <= n; i ++ )
    {
        int p;
        scanf("%d", &p);
        add(p, i);
    }

    getchar();
    for (int i = 1; i <= n; i ++ )
        scanf("%c", &c[i]);
    
    for (int i = 1; i <= m; i ++ )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        query[a].push_back({i, b});
    }

    dfs(1, 0);
    dfs2(1, 0);

    for (int i = 1; i <= m; i ++ )
        printf("%s\n", ans[i] ? "Yes" : "No");

    return 0;
}
