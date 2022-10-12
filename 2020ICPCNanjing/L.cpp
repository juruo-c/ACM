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

const int N = 100005;

int n, m;
int a[N], b[N];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int _; scanf("%d", &_);
    while (_ --)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i ++ )
            scanf("%d", &a[i]);
        for (int i = 1; i <= m; i ++ )
            scanf("%d", &b[i]);
        b[m + 1] = -2e9, b[m + 2] = 2e9;
        m += 2;
        sort(a + 1, a + 1 + n);
        sort(b + 1, b + 1 + m);
        int ans = 0;
        for (int i = 1; i < m; i ++ )
        {
            int l = upper_bound(a + 1, a + 1 + n, b[i]) - a;
            int r = lower_bound(a + 1, a + 1 + n, b[i + 1]) - a - 1;
            ans = max(r - l + 1, ans);
        }
        if (!ans) puts("Impossible");
        else printf("%d\n", ans);
    }
    return 0;
}
