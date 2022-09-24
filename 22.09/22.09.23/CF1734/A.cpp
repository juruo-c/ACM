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

LL solve(int a, int b, int c)
{
    return min(min(b - a + c - a, b - a + c - b), c - a + c - b);
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int _; scanf("%d", &_);
    while (_ --)
    {
        int n;
        scanf("%d", &n);
        vector<int> a(n);

        for (int i = 0; i < n; i ++ )
            scanf("%d", &a[i]);
        
        sort(a.begin(), a.end());
        
        LL ans = 1e18;
        for (int i = 0; i <= n - 3; i ++ )
            ans = min(solve(a[i], a[i + 1], a[i + 2]), ans);
            
        printf("%lld\n", ans);

    }
    return 0;
}
