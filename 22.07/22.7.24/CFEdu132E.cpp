#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>

using namespace std;

const int N = 200005;

int n;
int a[N], f[N];
set<int> s[N];
int ans = 0;

struct edge
{
    int to, next;
}e[N << 1];
int head[N], cnt;

void add(int u, int v)
{
    e[++ cnt] = edge{v, head[u]};
    head[u] = cnt;
}

void dfs1(int u, int ff)
{
    f[u] = f[ff] ^ a[u];
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == ff) continue;
        dfs1(v, u);
    }
}

void dfs2(int u, int ff)
{
    s[u].insert(f[u]);
    bool flag = false;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == ff) continue;
        dfs2(v, u);

        if (s[u].size() < s[v].size()) swap(s[u], s[v]);
        for (set<int>::iterator it = s[v].begin(); it != s[v].end(); it ++) 
            flag |= s[u].count((*it) ^ a[u]);
        for (set<int>::iterator it = s[v].begin(); it != s[v].end(); it ++)
            s[u].insert(*it);
    }
    if (flag)
    {
        ans ++;
        s[u].clear();
    }
}

int main()
{
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    int t = 1;
    while (t --)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
        for (int i = 1; i < n; i ++ )
        {
            int u, v;
            scanf("%d%d", &u, &v);
            add(u, v);
            add(v, u);
        }

        dfs1(1, 0);

        dfs2(1, 0);

        printf("%d\n", ans);

    }
    return 0;
}
