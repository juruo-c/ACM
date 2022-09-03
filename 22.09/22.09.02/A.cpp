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
int n;
int a[N];

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int _; scanf("%d", &_);
    while (_ --)
    {
        scanf("%d", &n);
        if (n <= 2)
        {
            puts("0");
            continue;
        }

        for (int i = 1; i <= n; i ++ )
            scanf("%d", &a[i]);
        sort(a + 1, a + 1 + n);
        
        LL ans = 0;
        for (int i = 1; i <= n; i ++ )
        {
            ans += 1LL * (n - i) * (a[i] - a[i - 1]);
            ans -= (a[i] - a[i - 1]);
        }

        printf("%lld\n", -ans);
    }
    return 0;
}
