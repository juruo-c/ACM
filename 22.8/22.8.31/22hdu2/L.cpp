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

const int N = 10000005;

LL f[N];

void pre()
{
    memset(f, 0x3f, sizeof f);
    vector<int> a(3);
    f[0] = 0;
    a[0] = 7, a[1] = 31, a[2] = 365;
    for (int i = 0; i < 3; i ++ )
        for (int j = a[i]; j < N; j ++ )
            f[j] = min(f[j], f[j - a[i]] + 1);

    // for (int i = 1; i <= 100; i ++ )
    //     cout << i << " " << f[i] << endl;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    pre();
    int _; scanf("%d", &_);
    while (_ --)
    {
        LL n;
        scanf("%lld", &n);
        if (n > 10000000)
        {
            LL ans = (n - 10000000) / 365;
            n -= (n - 10000000) / 365 * 365;
            ans += f[n];
            if (ans > 1e18) puts("-1");
            else printf("%lld\n", ans);
        }
        else printf("%lld\n", (f[n] > 1e18 ? -1 : f[n]));
    }
    return 0;
}
