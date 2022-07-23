#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <set>

using namespace std;

const int N = 10005, M = 2005;

int n, m;
set<int> e[N][M];
int f[2][M];

int main()
{
    int t = 1;
    while (t --)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i ++ )
        {
            int l;scanf("%d", &l);
            for (int j = 0; j < l; j ++ )
            {
                int u, v;
                scanf("%d%d", &u, &v);
                e[i][v].insert(u);
            }
        }

        f[0][1] = 1;
        int ans = 0x3f3f3f3f;
        for (int i = 1; i <= n; i ++ )
        {
            memset(f[i & 1], 0x3f, sizeof f[i & 1]);
            f[i & 1][1] = 1;
            for (auto x : e[i][1])
            for (int j = 2; j <= m; j ++ )
            {
                f[i & 1][j] = min(f[i & 1][j], f[i - 1 & 1][j] + 1);
                for (auto u : e[i - 1][j])
                    f[i & 1][j] = min(f[i & 1][j], f[i - 1 & 1][u] + 1);
            }
            ans = min(ans, f[i & 1][m]);
        }

        if (ans == 0x3f3f3f3f) puts("-1");
        else printf("%d\n", ans);

    }
    return 0;
}