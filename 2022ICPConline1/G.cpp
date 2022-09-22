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

const int N = 105;

int n, T;
LL x[5];
int w[N];
LL f[2][5][55][35][27][22];

bool check(int i, int j, int a, int b, int c, int d)
{
    if (f[i][j][a][b][c][d] < 0) return false;
    return a * x[1] + b * x[2] + c * x[3] + d * x[4] <= T;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif

    scanf("%d%d", &n, &T);
    for (int i = 1; i <= 4; i ++ )
        scanf("%lld", &x[i]);
    for (int i = 1; i <= n; i ++ )
        scanf("%d", &w[i]);

    memset(f[0], -0x3f, sizeof f[0]);
    f[0][0][0][0][0][0] = 0;
    for (int i = 0; i < n; i ++ )
    {
        memset(f[i + 1 & 1], -0x3f, sizeof f[i + 1 & 1]);
        for (int j = 0; j <= 4; j ++ )
            for (int a = 0; a <= (n + 1) / 2; a ++ )
                for (int b = 0; b <= min(a, 34); b ++ )
                    for (int c = 0; c <= min(b, 26); c ++ )
                        for (int d = 0; d <= min(21, c); d ++ )
                        {
                            if (!check(i & 1, j, a, b, c, d)) continue;
                            int t = i + 1 & 1;
                            LL x = f[i & 1][j][a][b][c][d];
                            f[t][0][a][b][c][d] = max(f[t][0][a][b][c][d], x);
                            if (j == 0)
                                f[t][1][a + 1][b][c][d] = max(f[t][1][a + 1][b][c][d], x + w[i + 1]);
                            if (j == 1)
                                f[t][2][a][b + 1][c][d] = max(f[t][2][a][b + 1][c][d], x + w[i + 1]);
                            if (j == 2)
                                f[t][3][a][b][c + 1][d] = max(f[t][3][a][b][c + 1][d], x + w[i + 1]);
                            if (j == 3)
                                f[t][4][a][b][c][d + 1] = max(f[t][4][a][b][c][d + 1], x + w[i + 1]);
                        }
    }

    LL ans = 0;
    for (int a = 0; a <= (n + 1) / 2; a ++ )
        for (int j = 0; j <= 4; j ++ )
            for (int b = 0; b <= min(a, 34); b ++ )
                for (int c = 0; c <= min(b, 26); c ++ )
                    for (int d = 0; d <= min(c, 21); d ++ )
                        if (check(n & 1, j, a, b, c, d))
                        {
                            // printf("a = %d b = %d c = %d d = %d f = %lld\n", a, b, c, d, f[n & 1][j][a][b][c][d]);
                            ans = max(ans, f[n & 1][j][a][b][c][d]);
                        }
        
    printf("%lld\n", ans);

    return 0;
}
