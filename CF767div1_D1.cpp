#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 2005, mod = 1000000007;

int n, m, k;
LL f[N][N];

LL qpow(LL a, int b)
{
    LL res = 1;
    while (b)
    {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main()
{
    int T;scanf("%d", &T);
    while (T --)
    {
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 1; i <= n; i ++ )
            f[i][0] = 0, f[i][i] = i;

        LL inv2 = qpow(2, mod - 2);
        for (int i = 2; i <= n; i ++ )
            for (int j = 1; j < i; j ++ )
            {
                f[i][j] = (f[i - 1][j - 1] + f[i - 1][j]) % mod * inv2 % mod;
            }

        printf("%lld\n", f[n][m] * k % mod);

    }
    return 0;
}
