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

const int N = 30, mod = 1000000007;

int n;
LL ai[N], mi[N];

LL exgcd(LL a, LL b, LL& x, LL& y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    LL d = exgcd(b, a % b, x, y);
    LL z = x;
    x = y;
    y = z - y * (a / b);
    return d;
}

LL mul(LL x, LL y, LL p)
{
    if (y < 0) x = -x, y = -y;
    LL z = (long double) x / p * y;
    LL res = (unsigned long long) x * y - (unsigned long long ) z * p;
    return (res + p) % p;
}

LL excrt()
{
    LL x, y, k;
    LL M = mi[1], ans = ai[1];
    for (int i = 2; i <= n; i ++ )
    {
        LL a = M, b = mi[i], c = (ai[i] - ans % b + b) % b;
        LL g = exgcd(a, b, x, y);
        if (c % g) return - 1;
        b /= g;
        c /= g;
        x = mul(x, c, b);
        ans += x * M;
        M *= b;
        ans = (ans % M + M) % M;
    }
    return (ans % M + M) % M;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    cin >> n;
    for (int i = 1; i <= n; i ++ )
        cin >> mi[i] >> ai[i];
    cout << excrt();
    return 0;
}
