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

int a[3][N];
int mx1[3][N];
int mx2[3][N];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int _; scanf("%d", &_);
    while (_ --)
    {
        memset(mx1, -0x3f, sizeof mx1);
        memset(mx2, -0x3f, sizeof mx2);
        int m;scanf("%d", &m);
        for (int i = 1; i <= 2; i ++ ) 
            for (int j = 1; j <= m; j ++ ) 
                scanf("%d", &a[i][j]);
        
        for (int i = 1; i <= 2; i ++ )
            for (int j = m; j >= 1; j -- )
            {
                mx1[i][j] = max(mx1[i][j + 1], a[i][j] - j);
                mx2[i][j] = max(mx2[i][j + 1], a[i][j] + j);
            }

        int ans = 2e9;
        int x = 1, y = 1, t = 0;
        for (int i = 1; i < 2 * m; i ++ )
        {
            int res = mx1[x][y + 1] + m + 1;
            res = max(res, t + m - y);
            // cout << "res1 = " << res << endl;
            res = max(res, a[(x == 1 ? 2 : 1)][m]) + 1;
            int ty = (i & 1 ? y : y + 1);
            int tt = mx2[(x == 1 ? 2 : 1)][ty] - ty + 1;
            res = max(tt, res + m - ty);
            ans = min(ans, res);
            // cout << "x = " << x << " y = " << y << " ans = " << ans << " t = " << t << endl;

            if (i & 1)
            {
                if (x == 1) x = 2;
                else x = 1;
            }
            else y ++;
            t = max(t, a[x][y]) + 1;
        }

        printf("%d\n", ans);

    }
    return 0;
}
