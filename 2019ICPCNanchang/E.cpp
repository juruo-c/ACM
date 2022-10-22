#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 50005, M = 500005;

int n, m, k;
struct edge
{
    int u, v, w;
    bool operator < (const edge& e) const 
    {
        return w > e.w;
    }
}E[M], unwhite[M], white[M];
int cnt, wcnt, uncnt;

int fa[N];
bool vis[N];

int getf(int x)
{
    return x == fa[x] ? x : fa[x] = getf(fa[x]);
}

int main()
{
    int _;
    scanf("%d", &_);
    while (_ --)
    {
        uncnt = wcnt = cnt = 0;
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 1; i <= n; i ++ ) fa[i] = i;

        LL ans = 0;
        for (int i = 1; i <= m; i ++ )
        {
            int u, v, w, c;
            scanf("%d%d%d%d", &u, &v, &w, &c);
            if (c == 1) white[++ wcnt] = {u, v, w};
            else 
            {
                ans += w;
                u = getf(u), v = getf(v);
                if (u != v)
                    fa[u] = v;
            }
        }

        for (int i = 1; i <= wcnt; i ++ )
        {
            int u = getf(white[i].u), v = getf(white[i].v);
            if (u != v)
                E[++ cnt] = white[i];
            else 
                unwhite[++ uncnt] = white[i];
        }

        sort(E + 1, E + 1 + cnt);
        for (int i = 1; i <= cnt; i ++ ) vis[i] = false;
        for (int i = 1; i <= cnt; i ++ )
        {
            int u = getf(E[i].u), v = getf(E[i].v);
            if (u != v && k)
            {
                vis[i] = true;
                ans += E[i].w;
                fa[u] = v;
                k --;
            }
        }

        bool flag = true;
        for (int i = 1; i <= n; i ++ )
            if (getf(i) != getf(1))
            {
                flag = false;
                break;
            }

        if (!flag)
        {
            puts("-1");
            continue;
        }

        if (k)
        {
            
            for (int i = 1; i <= cnt; i ++ )
                if (!vis[i])
                    unwhite[++ uncnt] = E[i];

            sort(unwhite + 1, unwhite + 1 + uncnt);
            for (int i = 1; i <= k; i ++ )
                ans += unwhite[i].w;
        }
        printf("%lld\n", ans);
    }
    return 0;
}