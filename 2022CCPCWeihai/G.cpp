#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long LL;

const int N = 3000005;

int n, x;
int g[N];
int sum[N];

LL gcd(LL a, LL b)
{
    while (b)
    {
        LL t = a;
        a = b;
        b = t % b;
    }
    return a;
}

int main()
{

    scanf("%d%d", &x, &n);
    LL t = x;
    while (t % 2 == 0)
        t /= 2;
    double tt = log2(t);
    if (tt != (int)tt) t = (int)tt + 1;
    else t = (int)tt;
    int T = 1 << t;

    for (int i = 1; i <= T; i ++ )
        g[i] = gcd((1LL * i * x) ^ x, x), g[i + T] = g[i];
    
    for (int i = 1; i <= 2 * T; i ++ )
        if (g[i] == 1)
            sum[i] = sum[i - 1] + 1;
        else sum[i] = sum[i - 1];

    for (int i = 1; i <= n; i ++ )
    {
        LL l, r;
        scanf("%lld%lld", &l, &r);
        LL len = r - l + 1;
        if (len < T)
        {
            l = (l - 1) % T + 1;
            printf("%d\n", sum[l + len - 1] - sum[l - 1]);
        }
        else 
        {
            LL ans = 1LL * sum[T] * (len / T);
            t = len - len / T * T;
            r = r - t + 1;
            r = (r - 1) % T + 1;
            if (t)
                ans += sum[r + t - 1] - sum[r - 1];
            printf("%lld\n", ans);
        }
    }

    return 0;
}