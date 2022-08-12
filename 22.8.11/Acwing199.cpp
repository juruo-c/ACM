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
    int n, k;
    scanf("%d%d", &n, &k);
    LL ans = 1LL * n * k;
    for (int l = 1, r; l <= n; l = r + 1)
    {
        if (k / l)
            r = min(n, k / (k / l));
        else r = n;
        ans -= 1LL * (k / l) * (r - l + 1) * (l + r) / 2;
    }
    printf("%lld\n", ans);
    return 0;
}
