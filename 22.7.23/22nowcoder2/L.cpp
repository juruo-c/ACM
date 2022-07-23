#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <set>

using namespace std;

const int N = 10005, M = 2005;

int n, m;
int g[M], f[M];

int main()
{
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    int t = 1;
    while (t --)
    {
        scanf("%d%d", &n, &m);

        int ans = n + 1;
        memset(g, 0x3f, sizeof g);
        memset(f, 0x3f, sizeof f);
        g[1] = 1;
        for (int i = 1; i <= n; i ++ )
        {
            memcpy(g, f, sizeof f);
            for (int j = 1; j <= m; j ++ )
                f[j] ++;
            f[1] = 1;
            int l;scanf("%d", &l);
            for (int j = 0; j < l; j ++ )
            {
                int u, v;
                scanf("%d%d", &u, &v);
                if (u == 1) f[v] = 1;
                f[v] = min(f[v], g[u] + 1);
            }
            ans = min(ans, f[m]);
        }

        if (ans == n + 1) puts("-1");
        else printf("%d\n", ans);
    }
    return 0;
}