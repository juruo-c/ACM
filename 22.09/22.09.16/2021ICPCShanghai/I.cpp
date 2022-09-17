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

const int N = 105, M = 5500;
const int base = 2600;

int n, k;
LL f[N][M][N];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    
    memset(f, -0x3f, sizeof f);
    f[0][0 + base][0] = 0;

    scanf("%d%d", &n, &k);
    int v, t;
    for (int i = 1; i <= n; i ++ )
    {
        scanf("%d%d", &v, &t);
        for (int j = 0; j <= 2 * base; j ++ )
            for (int s = 0; s <= k; s ++ )
            {
                LL& x = f[i][j][s];
                x = max(x, f[i - 1][j][s]);
                if (j >= t) x = max(x, f[i - 1][j - t][s] + v);
                if (j + t <= 2 * base) x = max(x, f[i - 1][j + t][s] + v);
                if (j >= 2 * t && s) x = max(x, f[i - 1][j - 2 * t][s - 1] + v);
                if (j + 2 * t <= 2 * base && s) x = max(x, f[i - 1][j + 2 * t][s - 1] + v);
            }
    }

    LL ans = -1e18;
    for (int i = 0; i <= k; i ++ )
        ans = max(ans, f[n][0 + base][i]);
    printf("%lld\n", ans);

    return 0;
}
