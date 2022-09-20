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

const int N = 105;

int a[N], mx[N];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int _; scanf("%d", &_);
    while (_ --)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i ++ )
            scanf("%d", &a[i]);
        memset(mx, 0, sizeof mx);
        for (int i = 1; i <= n; i ++ )
            mx[i % k] = max(mx[i % k], a[i]);
        
        LL ans = 0;
        for (int i = 0; i < k; i ++ )
            ans += mx[i];
        printf("%lld\n", ans);
    }
    return 0;
}
