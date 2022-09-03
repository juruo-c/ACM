#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#define ZYCMH

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100005, mod = 1000000007;

LL getphi(LL x)
{
    LL res = x;
    LL t = x;
    for (LL i = 2; i * i <= x; i ++ )
    {
        if (t % i == 0)
        {
            res = res * (i - 1) / i;
            while (t % i == 0)
                t /= i;
        }
    }
    if(t > 1) res = res * (t - 1) / t;

    return res;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int t = 1;
    while (t --)
    {
        LL n;
        scanf("%lld", &n);
        LL ans = 0;
        for (LL i = 1; i * i <= n; i ++ )
        {
            if (n % i == 0)
            {
                ans += i * getphi(n / i);
                if (i * i != n)
                    ans += 1LL * n / i * getphi(i);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
