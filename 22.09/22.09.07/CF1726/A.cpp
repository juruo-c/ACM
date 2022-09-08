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

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int _; scanf("%d", &_);
    while (_ --)
    {
        int n;scanf("%d", &n);
        vector<int> a(n);
        for (int i = 0; i < n; i ++ )
            scanf("%d", &a[i]);
        if (n == 1)
        {
            puts("0");
            continue;
        }
        int mx = -1e9;
        for (int i = 0; i < n; i ++ )
            mx = max(mx, a[n - 1] - a[i]);
        for (int i = 1; i < n; i ++ )
            mx = max(mx, a[i] - a[0]);
        for (int i = 0; i < n; i ++ )
            mx = max(mx, a[i] - a[(i + 1) % n]);
        printf("%d\n", mx);
    }
    return 0;
}
