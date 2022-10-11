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

const int N = 205;

int n;
double f[N][N][N];

double dfs(int i, int j, int k)
{
    if (f[i][j][k] != -1) return f[i][j][k];

    f[i][j][k] = 0;

    int all = 0;
    if (i >= 2) all += i * (i - 1), f[i][j][k] += (dfs(i - 2, j + 1, k) + 1) * i * (i - 1);
    if (i >= 1 && j >= 1) all += i * 4 * j, f[i][j][k] += (dfs(i - 1, j - 1, k + 1) + 1) * i * 4 * j;
    if (i >= 1) all += i * 4 * k, f[i][j][k] += (dfs(i - 1, j, k) + 1) * i * 4 * k;
    if (j >= 2) all += j * (j - 1) * 4, f[i][j][k] += (dfs(i, j - 2, k + 1) + 1) * j * (j - 1) * 4;
    if (j >= 1) all += j * k * 8, f[i][j][k] += (dfs(i, j - 1, k) + 1) * j * k * 8;
    if (k >= 1) all += k * (k - 1) * 4, f[i][j][k] += ( dfs(i, j, k - 1) + 1 ) * k * (k - 1) * 4;
    if (k >= 1) all += 2 * k, f[i][j][k] += (dfs(i, j, k - 1) + 1) * 2 * k;
    f[i][j][k] += n * n - all;
    f[i][j][k] /= all;

    return f[i][j][k];

}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif 
    scanf("%d", &n);
    for (int i = 0; i <= n; i ++ )
        for (int j = 0; j <= n; j ++ )
            for (int k = 0; k <= n; k ++ )
                f[i][j][k] = -1;
    
    f[1][0][0] = f[0][1][0] = f[0][0][0] = 0;
    printf("%.10f\n", dfs(n, 0, 0));
    return 0;
}
