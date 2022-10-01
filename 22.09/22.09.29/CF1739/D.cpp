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

const int N = 200005;

int n, k;
struct edge
{
    int to, next;
}e[N << 1];
int head[N], cnt;
int depth[N];
int res;

void add(int u, int v)
{
    e[++ cnt] = {v, head[u]};
    head[u] = cnt;
}

void dfs(int u, int ff, int Mxdep)
{
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == ff) continue;
        dfs(v, u, Mxdep);
        if (u != 1 && Mxdep == depth[v] + 1)
            res ++;
        else depth[u] = max(depth[v] + 1, depth[u]);
    }
}

bool check(int x)
{
    res = 0;
    for (int i = 1; i <= n; i ++ ) depth[i] = 0;
    dfs(1, 0, x);
    return res <= k;
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
        cnt = 0;
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i ++ )
            head[i] = 0;
        for (int i = 2; i <= n; i ++ )
        {
            int p;
            scanf("%d", &p);
            add(p, i);
        }

        int l = 1, r = n;
        
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        printf("%d\n", r);
    }
    return 0;
}
