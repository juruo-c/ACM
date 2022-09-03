#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <bitset>
#define ZYCMH

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1024;
bitset<1024> f[2][N];


int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int _; scanf("%d", &_);
    while (_ --)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        memset(f, 0, sizeof f);
        f[0][0][0] = 1;
        int ans = -1;
        bool cur = 1;
        for (int i = 1; i <= n; i ++ )
        {
            int v, w;
            scanf("%d%d", &v, &w);
            for (int j = 0; j < 1024; j ++ )
            {
                f[cur][j] = f[cur ^ 1][j] | (f[cur ^ 1][j ^ w] << v);
                if (i == n && f[cur][j][m])
                    ans = max(ans, j); 
            }
            cur ^= 1;
        }
        printf("%d\n", ans); 
    }
    return 0;
}
