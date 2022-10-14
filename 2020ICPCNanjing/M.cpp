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

const int N = 2005;
const LL INF = 1e18;

int n;
struct edge
{
    int to, next;
}e[N << 1];
int head[N], cnt;
int hp[N];
int siz[N];
LL f[N][N][2], g[N][2];

void add(int u, int v)
{
    e[++ cnt] = {v, head[u]};
    head[u] = cnt;
}

void dfs(int u)
{
    f[u][0][0] = hp[u], f[u][1][1] = 0;
    siz[u] = 1;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        dfs(v);

        for (int j = siz[u] + siz[v]; j >= 0; j -- )
            g[j][1] = g[j][0] = INF;

        for (int j = siz[u]; j >= 0; j -- )
        {
            for (int k = siz[v]; k >= 0; k -- )
            {
                g[j + k][1] = min(g[j + k][1], min(f[v][k][0], f[v][k][1]) + f[u][j][1]);
                g[j + k][0] = min(g[j + k][0], min(f[v][k][0] + hp[v], f[v][k][1]) + f[u][j][0]);
            }
        }
        for (int j = siz[u] + siz[v]; j >= 0; j -- )
            f[u][j][1] = g[j][1], f[u][j][0] = g[j][0];
        siz[u] += siz[v];
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
        scanf("%d", &n);
     
        cnt = 0;
        for (int i = 1; i <= n; i ++ )
            head[i] = 0;
        for (int i = 0; i <= n; i ++ )
            for (int j = 0; j <= n; j ++ )
                f[i][j][0] = f[i][j][1] = INF;

        for (int i = 2; i <= n; i ++ )
        {
            int p;scanf("%d", &p);
            add(p, i);
        }
        for (int i = 1; i <= n; i ++ )
            scanf("%d", &hp[i]);

        dfs(1);

        for (int i = 0; i <= n; i ++ )
        {
            if (i) printf(" ");
            printf("%lld", min(f[1][i][0], f[1][i][1])); 
        }
        puts("");       
    }
    return 0;
}
