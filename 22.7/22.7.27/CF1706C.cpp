#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100005, mod = 1000000007;

int n;
int h[N];
LL pre[N], suf[N];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int t; scanf("%d", &t);
    while (t --)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++ ) scanf("%d", &h[i]);
        
        if (n % 2)
        {
            LL ans = 0;
            for (int i = 2; i < n; i += 2)
                if (h[i] <= h[i - 1] || h[i] <= h[i + 1])
                    ans += max(h[i - 1], h[i + 1]) + 1 - h[i];
            printf("%lld\n", ans);
            continue;
        }

        memset(pre, 0, sizeof pre);
        memset(suf, 0, sizeof suf);

        for (int i = 2; i < n; i += 2)
        {
            pre[i] = pre[i - 2];
            if (h[i] <= h[i - 1] || h[i] <= h[i + 1]) 
                pre[i] += max(h[i - 1], h[i + 1]) + 1 - h[i];
        }

        for (int i = n - 1; i > 1; i -= 2)
        {
            suf[i] = suf[i + 2];
            if (h[i] <= h[i - 1] || h[i] <= h[i + 1])
                suf[i] += max(h[i - 1], h[i + 1]) + 1 - h[i];
        }

        LL ans = 1e18;
        for (int i = 2; i <= n; i += 2 )
            ans = min(ans, pre[i - 2] + suf[i + 1]);
        printf("%lld\n", ans);
    }
    return 0;
}
