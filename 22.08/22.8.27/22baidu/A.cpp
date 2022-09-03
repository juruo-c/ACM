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

const int N = 10005;

struct edge
{
    int u, v, w;
    bool operator < (const edge& b) const 
    {
        return w < b.w;
    }
}e[N];
int cnt;
int fa[105];

int getf(int x)
{
    return x == fa[x] ? x : fa[x] = getf(fa[x]);
}

bool cmp(edge& a, edge& b)
{
    if (a.u == b.u) return a.v < b.v;
    return a.u < b.u;
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
        int n;
        scanf("%d", &n);
        cnt = 0;
        for (int i = 1; i <= n; i ++ ) fa[i] = i;
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= n; j ++ )
            {
                int w;
                scanf("%d", &w);
                if (j > i)
                    e[++ cnt] = {i, j, w};
            }

        vector<edge> ans;
        sort(e + 1, e + 1 + cnt);
        for (int i = 1; i <= cnt; i ++ )
        {
            int u = getf(e[i].u), v = getf(e[i].v);
            if (u != v)
            {
                ans.push_back(e[i]);
                fa[u] = v;
            }
        }

        sort(ans.begin(), ans.end(), cmp);
        printf("%d\n", n - 1);
        for (int i = 0; i < ans.size(); i ++ )
            printf("%d %d\n", ans[i].u, ans[i].v);
    }
    return 0;
}
