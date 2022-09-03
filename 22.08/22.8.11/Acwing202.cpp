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

LL gcd(LL a, LL b)
{
    return !b ? a : gcd(b, a % b);
}

LL phi(LL n)
{   
    LL ans = n;
    for (LL i = 2; i * i <= n; i ++ )
    {
        if (n % i == 0)
        {
            ans = ans / i * (i - 1);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) ans = ans / n * (n - 1);
    return ans;
}

LL qmul(LL a, LL b, LL p)
{
    a %= p;
    LL res = 0;
    while (b)
    {
        if (b & 1) res = (res + a) % p;
        a = (a + a) % p;
        b >>= 1;
    }
    return res;
}

LL qpow(LL a, LL b, LL p)
{
    LL res = 1;
    while (b)
    {
        if (b & 1) res = qmul(res, a, p);
        a = qmul(a, a, p);
        b >>= 1;
    }
    return res;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int kase = 0;
    int L;
    while (scanf("%d", &L) && L)
    {
        // printf("L = %d\n", L);
        int d = gcd(L, 8);
        // printf("d = %d\n", d);
        LL t = 1LL * L / d * 9;
        // printf("t = %lld\n", t);
        if (gcd(t, 10) != 1LL) 
        {
            printf("Case %d: 0\n", ++ kase);
            continue;
        }
        LL tt = phi(t);
        printf("t = %lld tt = %lld\n", t, tt);
        LL ans = 1e18;
        for (LL i = 1; i * i <= tt; i ++ )
        {
            if (tt % i == 0)
            {
                // printf("i = %lld\n", i);
                if (qpow(10, i, t) == 1LL)
                    ans = min(ans, i);
                if (i * i != tt)
                {
                    if (qpow(10, tt / i, t) == 1LL)
                        ans = min(ans, tt / i);
                }
            }
        }
        if (ans == 1e18) printf("Case %d: 0\n", ++kase);
        else printf("Case %d: %lld\n", ++ kase, ans);
    }
    return 0;
}
