#include <bits/stdc++.h>

using namespace std;

const int N = 500005;

int n;
struct edge
{
    int to, next;
}e[N << 1];
int head[N], cnt;
int f[N][3];

void add(int u, int v)
{
    e[++ cnt] = {v, head[u]};
    head[u] = cnt;
}

void dfs(int u, int ff)
{
    f[u][0] = f[u][1] = f[u][2] = 0;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == ff) continue;
        dfs(v, u);
        f[u][0] += max(f[v][0], f[v][1]);
        f[u][1] = max(1 + f[v][2] - f[v][0], f[u][1]);
        f[u][2] += f[v][0];
    }
    f[u][1] += f[u][2] + 1;
}

int main()
{
    int _;
    scanf("%d", &_);
    while (_ --)
    {
        scanf("%d", &n);
        cnt = 0;
        memset(head, 0, sizeof head);
        for (int i = 1; i < n; i ++ )
        {
            int u, v;
            scanf("%d%d", &u, &v);
            add(u, v);
            add(v, u);
        }

        dfs(1, 0);

        printf("%d\n", max(f[1][0], f[1][1]));
    }
    return 0;
}