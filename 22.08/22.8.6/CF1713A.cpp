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

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int t; scanf("%d", &t);
    while (t --)
    {
        int n;
        scanf("%d", &n);
        int mix = 1000, mxx = -1000, miy = 1000, mxy = -1000;
        for (int i = 1; i <= n; i ++ )
        {
            int x, y;
            scanf("%d%d", &x, &y);
            if (x == 0) miy = min(y, miy), mxy = max(mxy, y);
            else mix = min(x, mix), mxx = max(x, mxx);
        }
        int ans = 0;
        if (mxx > 0) ans += 2 * mxx;
        if (mix < 0) ans += - 2 * mix;
        if (mxy > 0) ans += 2 * mxy;
        if (miy < 0) ans += - 2 * miy;
        printf("%d\n", ans);
    }
    return 0;
}
