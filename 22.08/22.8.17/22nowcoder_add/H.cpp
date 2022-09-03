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

const int N = 100005, mod = 1000000007;

int n, q;
struct edge
{
    int to, next;
}e[N << 1];
int head[N], cnt;
 
void add(int u, int v)
{
    e[++ cnt] = {v, head[u]};
    head[u] = cnt;
}

LL f[N], g[N];
int a[N], b[N];
int siz[N];

int getnum(int x, int num)
{
    int res = 0;
    while (x % num == 0) x /= num, res ++;
    return res;
}

void dfs1(int u, int ff)
{
    siz[u] = 1;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == ff) continue;
        dfs1(v, u);
        siz[u] += siz[v];
    }
}

void dfs(int u, int ff)
{
    for (int i = head[u]; i;i = e[i].next)
    {
        int v = e[i].to;
        if (v == ff) continue;
        f[v] = f[u] + 1LL * a[u] * (siz[u] - siz[v]);
        g[v] = g[u] + 1LL * b[u] * (siz[u] - siz[v]);
        dfs(v, u);
    }
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    
    scanf("%d%d", &n, &q);
    for (int i = 1; i < n; i ++ )
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }

    for (int i = 1; i <= n; i ++ )
        a[i] = getnum(i, 2), b[i] = getnum(i, 5);

    // for (int i = 1; i <= n; i ++ )
    //     printf("a[%d] = %d b[%d] = %d\n", i, a[i], i, b[i]);

    dfs1(1, 0);
    dfs(1, 0);

    for (int i = 1; i <= n; i ++ )
        f[i] += 1LL * a[i] * siz[i], g[i] += 1LL * b[i] * siz[i];

    for (int i = 1; i <= q; i ++ )
    {
        int x;
        scanf("%d", &x);
        printf("%lld\n", min(f[x], g[x]));
    }
    return 0;
}
