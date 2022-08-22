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

const int N = 100005, mod = 1000000007;

int h[15], m[15];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int t; scanf("%d", &t);
    while (t --)
    {
        int n, H, M;
        scanf("%d%d%d", &n, &H, &M);
        for (int i = 1; i <= n; i ++ ) scanf("%d%d", &h[i], &m[i]);
        
        int ans = 0;
        while (true)
        {
            bool flag = false;
            for (int i = 1; i <= n; i ++ )
                if (h[i] == H && m[i] == M)
                {
                    flag = true;
                    break;
                }
            if (flag) break;
            M ++;
            if (M == 60) M = 0, H ++;
            if (H > 23) H = 0;
            ans ++;
        }

        printf("%d %d\n", ans / 60, ans % 60);

    }
    return 0;
}
