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
const int N = 5e3 + 10;
int f[N][81][200], n, a[N];
//f[i][j][k]表示到第i场 w增加了j次 输了k场可获得的最后最大值
int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int _ = 1;
    while (_ --)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
        f[0][0][0] = 1;
        int ans = 0;
        for(int i = 0; i < n; i ++)
        {
            for(int j = 0; j < 80; j ++)
            {
                for(int k = 0; k < 140; k ++)
                {
                    if(!f[i][j][k]) continue;
                    //增加
                    if(f[i][j][k] >= a[i + 1]) f[i + 1][j + 1][k] = max(f[i + 1][j + 1][k], f[i][j][k]);
                    else f[i + 1][j + 1][k + 1] = max(f[i + 1][j + 1][k + 1], f[i][j][k]);
                    //不增加
                    if(f[i][j][k] + j + 1 >= a[i + 1]) f[i + 1][j][k] = max(f[i + 1][j][k], f[i][j][k] + j + 1);
                    else f[i + 1][j][k + 1] = max(f[i + 1][j][k + 1], f[i][j][k] + j + 1);
                }
            }
        }
        for(int j = 0; j <= 80; j ++)
            for(int k = 0; k <= min(n, 140); k ++) 
                if (f[n][j][k])
                    ans = max(n - k, ans);
        printf("%d\n", ans);
    }
    return 0;
}
