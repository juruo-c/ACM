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

int a[N];
int b[N];
LL f[N][N];
LL g[N][N];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ )
        scanf("%d", &a[i]);
    
    LL ans = 0;
    for (int i = 2; i <= n; i ++ )
        ans += 1LL * (a[i] - a[i - 1]) * (a[i] - a[i - 1]), b[i - 1] = a[i] - a[i - 1];
    n --;

    // printf("%lld\n", ans);

    for (int i = 1; i <= n; i ++ )
        for (int j = i + 1; j <= n; j ++ )
        {
            LL sum = b[i];
            for (int k = i + 1; k <= j; k ++ )
                g[i][j] += sum * b[k], sum += b[k];
            g[i][j] *= 2;
        }
    
    // for (int i = 1; i <= n; i ++ )
    //     for (int j = i + 1; j <= n; j ++ )
    //         printf("l = %d r = %d g[i][j] = %lld\n", i, j, g[i][j]);

    for (int i = 1; i <= n; i ++ )
        for (int j = 0; j <= i - 1; j ++ )
            for (int k = 0; k <= j; k ++ )
                f[i][j] = max(f[i][j], f[i - (k + 1)][j - k] + g[i - k][i]);

    for (int j = 1; j <= n + 1; j ++ )
        printf("%lld\n", ans + f[n][min(n - 1, j * 2)]);

    return 0;
}
