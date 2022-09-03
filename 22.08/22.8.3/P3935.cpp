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

const int N = 100005, mod = 998244353;

LL calc(LL n)
{
    LL ans = 0;
    for (LL l = 1, r; l <= n; l = r + 1)
    {
        r = n / (n / l);
        ans = (ans + (r - l + 1) * (n / l) % mod) % mod;
    }
    return ans;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    LL l, r;
    scanf("%lld%lld", &l, &r);

    printf("%lld\n", (calc(r) - calc(l - 1) + mod) % mod);

    return 0;
}
