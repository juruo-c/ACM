#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100005, mod = 1000000007;

LL exgcd(LL a, LL b, LL& x, LL& y)
{
    if (!b) 
    {
        x = 1, y = 0;
        return a;
    }
    LL gcd = exgcd(b, a % b, x, y);
    LL z = x;
    x = y;
    y = z - y * (a / b);
    return gcd;
}

int main()
{
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    int t = 1;
    while (t --)
    {
        LL x, y, m, n, L;
        cin >> x >> y >> m >> n >> L;
        LL a = m - n, b = L, c = y - x;

        LL gcd = exgcd(a, b, x, y);

        if (c % gcd)
            puts("Impossible");
        else
        {
            x *= c / gcd, b = abs(b / gcd);
            printf("%lld\n", (x % b + b) % b);
        }

    }
    return 0;
}
