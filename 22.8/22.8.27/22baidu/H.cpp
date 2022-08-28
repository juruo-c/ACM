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

const int N = 10005, INF = 0x3f3f3f3f;

int n, m;
int f[N][N], h[N][N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int dfs(int x, int y)
{
    if (f[x][y] != -1) return f[x][y];
    if (h[x][y] == 0) return f[x][y] = 0;
    f[x][y] = INF;
    for (int i = 0; i < 4; i ++ )
    {
        int tx = x + dx[i], ty = y + dy[i];
        if (tx < 1 || tx > n || ty < 1 || ty > m || h[tx][ty] > h[x][y]) continue;
        f[x][y] = min(f[x][y], dfs(tx, ty) + 1);
    }
    return f[x][y];
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            scanf("%d", &h[i][j]);

    memset(f, -1, sizeof f);

    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            dfs(i, j);

    for (int i = 1; i <= n; i ++ )
    {
        for (int j = 1; j <= m; j ++ )
            printf("%d ", f[i][j] == INF ? -1 : f[i][j]);
        puts("");
    }

    return 0;
}
