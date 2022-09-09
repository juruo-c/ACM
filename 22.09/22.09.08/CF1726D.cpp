#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 200005;

struct edge
{
    int u, v;
}e[N];
int fa[N];
int ans[N];
int getf(int x)
{
    return x == fa[x] ? x : fa[x] = getf(fa[x]);
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
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i ++ )
            ans[i] = 0, scanf("%d%d", &e[i].u, &e[i].v);
        vector<int> E;
        for (int i = 1; i <= n; i ++ )
            fa[i] = i;
        
        for (int i = 1; i <= m; i ++ )
        {
            int u = getf(e[i].u), v = getf(e[i].v);
            if (u != v)
            {
                fa[u] = v;
                ans[i] = 1;
            }
            else E.push_back(i);
        }

        if (E.size() == 3)
        {
            set<int> v;
            for (int i = 0; i < E.size(); i ++ )
                v.insert(e[E[i]].u), v.insert(e[E[i]].v);
            if (v.size() == 3)
            {
                ans[E[0]] = 1;
                int vertex = e[E[0]].u;
                for (int i = 1; i <= m; i ++ )
                {
                    if (i == E[0]) continue;
                    if (e[i].u == vertex || e[i].v == vertex)
                        ans[i] = 0;
                }
            }
        }

        for (int i = 1; i <= m; i ++ )
            printf("%d", ans[i]);
        puts("");

    }
    return 0;
}
