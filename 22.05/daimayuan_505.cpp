//http://oj.daimayuan.top/course/10/problem/505
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 100005;

int n;
struct edge
{
    int to, next;
}e[N << 1];
int head[N], cnt;

int siz[N];
LL f[N];


void add(int u, int v)
{
    e[++ cnt] = {v, head[u]};
    head[u] = cnt;
}

void dfs(int u, int ff)
{
    siz[u] = 1;
    f[u] = 1LL * (n - 1) * (n - 2) / 2;
    for (int i = head[u]; i; i = e[i].next )
    {
        int v = e[i].to;
        if (v == ff) continue;
        dfs(v, u);
        siz[u] += siz[v];
        f[u] -= 1LL * siz[v] * (siz[v] - 1) / 2;
    }
    f[u] -= 1LL * (n - siz[u]) * (n - siz[u] - 1) / 2;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i ++ )
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add(u, v);
        add(v, u);
    }

    dfs(1, 0);

    LL ans = 1LL * n * (n - 1) * (n - 2) / 6;

    for (int i = 1; i <= n; i ++ )
        ans -= f[i];

    printf("%lld\n", ans);

    return 0;
}
