#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100005, mod = 1000000007;

int jc[N], jc_inv[N];

int qpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1) res = 1LL * res * a % mod;
        a = 1LL * a * a % mod;
        b >>= 1;
    }
    return res;
}

int C(int n, int m)
{
    return 1LL * jc[n] * jc_inv[m] % mod * jc_inv[n - m] % mod;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif
    jc[0] = jc_inv[0] = 1;
    for (int i = 1; i < N; i ++ )
        jc[i] = 1LL * jc[i - 1] * i % mod;
    jc_inv[N - 1] = qpow(jc[N - 1], mod - 2);
    for (int i = N - 2; i >= 1; i -- )
        jc_inv[i] = 1LL * jc_inv[i + 1] * (i + 1) % mod;
    
    int n, k;
    scanf("%d%d", &n, &k);

    int ans = 0;
    for (int i = 0; i <= min(n, k); i ++ )
        ans = (ans + C(n, i)) % mod;

    printf("%d\n", ans);

    return 0;
}
