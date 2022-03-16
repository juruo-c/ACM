//http://oj.daimayuan.top/course/10/problem/556

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 500005;

int n;
int w[N];
struct edge
{
    int to, next;
}e[N << 1];
int head[N], cnt;
int f[N][2];

void add(int u, int v)
{
    e[++ cnt] = {v, head[u]};
    head[u] = cnt;
}

void dfs(int u, int ff)
{
    f[u][0] = f[u][1] = 1;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == ff) continue;
        dfs(v, u);
        if ((w[v] + 1) % 3 == w[u]) f[u][0] = max(f[u][0], f[v][0] + 1);
        if ((w[u] + 1) % 3 == w[v]) f[u][1] = max(f[u][1], f[v][1] + 1);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i ++ )
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }
    for (int i = 1; i <= n; i ++ ) scanf("%d", &w[i]);

    dfs(1, 0);

    int ans = 0;
    for (int i = 1; i <= n; i ++ )
        ans = max(ans, f[i][0] + f[i][1] - 1);

    printf("%d\n", ans);

    return 0;
}
