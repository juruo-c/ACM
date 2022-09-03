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

const int N = 505, INF = 0x3f3f3f3f;

int n, m, k, q;
int a[N][N];
int stf[N][15][N], stg[N][15][N];
int lg[N];

int query(int st[][N], int l, int r)
{
    int k = lg[r - l + 1];
    return max(st[k][l], st[k][r - (1 << k) + 1]);
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    memset(a, 0x3f, sizeof a);
    for (int i = 2; i < N; i ++ ) lg[i] = lg[i / 2] + 1;
    scanf("%d%d%d", &n, &m, &k);
    int _; scanf("%d", &_);
    while (_ --)
    {
        int x, y, t;
        scanf("%d%d%d", &x, &y, &t);
        a[x][y] = t;
    }

    for (int i = 1; i <= n; i ++ )
    {
        for (int j = 1; j <= m; j ++ )
        {
            stf[i][0][j] = a[i][j];
        }
        for (int k = 1; k < 15; k ++ )
            for (int j = 1; j + (1 << k) - 1 <= m; j ++ )
                stf[i][k][j] = max(stf[i][k - 1][j], stf[i][k - 1][j + (1 << (k - 1))]);
    }

    for (int j = 1; j <= m; j ++ )
    {
        for (int i = 1; i <= n; i ++ )
            stg[j][0][i] = a[i][j];
        for (int k = 1; k < 15; k ++ )
            for (int i = 1; i + (1 << k) - 1 <= n; i ++ )
                stg[j][k][i] = max(stg[j][k - 1][i], stg[j][k - 1][i + (1 << (k - 1))]);
    }

    int ans = INF;
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            for (int l = k; ; l ++ )
            {
                if (i + l - 1 > n || j + l - 1 > m) break;
                int rr = j + l - 1, dr = i + l - 1;
                // printf("%d %d %d %d\n", i, j, rr, dr);
                int A = query(stf[i], j, rr), B = query(stg[j], i, dr);
                int C = query(stf[dr], j, rr), D = query(stg[rr], i, dr);

                if (A != INF && B != INF && C != INF && D != INF)
                    ans = min(ans, max(max(max(A, B), C), D));
            }

    if (ans == INF)
        puts("-1");
    else printf("%d\n", ans);

    return 0;
}
