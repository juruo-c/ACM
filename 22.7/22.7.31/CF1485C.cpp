#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100005, mod = 1000000007;

int x, y;

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int t; scanf("%d", &t);
    while (t --)
    {
        scanf("%d%d", &x, &y);
        LL ans = 0;
        for (int i = 1; i <= min(y, (int)sqrt(x)); i ++ )
            ans += (1LL * i * i + i - 1) / (i + 1);

        if (y <= (int)sqrt(x))
        {
            printf("%lld\n", ans);
            continue;
        }

        for (int l = (int)sqrt(x) + 2, r; l <= y + 1; l = r + 1 )
        {
            if (x / l)
                r = min(y + 1, x / (x / l));
            else r = y + 1;
            ans += (x / l) * (r - l + 1);

        }
        printf("%lld\n", ans);
    }
    return 0;
}
