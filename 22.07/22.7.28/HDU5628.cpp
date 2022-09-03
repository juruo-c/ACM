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

int n, k;
LL f[N], res[N], I[N], h[N];

void Dirichlet(LL* f, LL* g)
{
    for (int i = 1; i <= n; i ++ ) h[i] = 0;
    for (int i = 1; i <= n; i ++ )
        for (int j = i; j <= n; j += i)
            h[j] = (h[j] + f[i] * g[j / i]) % mod;
    for (int i = 1; i <= n; i ++ ) f[i] = h[i];
}

void qpow(LL* a, LL* b, int k)
{
    while (k)
    {
        if (k & 1) Dirichlet(a, b);
        Dirichlet(b, b);
        k >>= 1;
    }
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    int t; scanf("%d", &t);
    while (t --)
    {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i ++ ) scanf("%lld", &f[i]), res[i] = 0, I[i] = 1;
        res[1] = 1;
        qpow(res, I, k);
        Dirichlet(f, res);

        for (int i = 1; i <= n; i ++ )
        {
            if (i > 1) printf(" ");
            printf("%lld", f[i]);
        }
        puts("");
    }
    return 0;
}
