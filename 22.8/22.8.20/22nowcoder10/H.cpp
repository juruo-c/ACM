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

const int mod = 998244353, N = 20000005;

int A, a[8];
int B, b[8];
int jc[N], jc_inv[N];
int pow2[N];

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

int CC(int n, int m)
{
    if (n < m) return 1;
    return 1LL * jc[n] * jc_inv[m] % mod * jc_inv[n - m] % mod;
}

int main()
{
    #ifdef ZYCMH
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif

    scanf("%d", &A); 
    if (A % 10) A = A / 10 + 1;
    else A = A / 10;
    for (int i = 1; i <= 7; i ++ )
        scanf("%d", &a[i]);
    scanf("%d", &B);
    if (B % 10) B = B / 10 + 1;
    else B = B / 10;
    for (int i = 1; i <= 7; i ++ ) 
        scanf("%d", &b[i]);

    int n = A + B;
    jc[0] = jc_inv[0] = 1;
    for (int i = 1; i <= n; i ++ )
        jc[i] = 1LL * i * jc[i - 1] % mod;
    jc_inv[n] = qpow(jc[n], mod - 2);
    for (int i = n - 1; i >= 1; i -- )
        jc_inv[i] = 1LL * jc_inv[i + 1] * (i + 1) % mod;
    pow2[0] = 1;
    int inv2 = qpow(2, mod - 2);
    for (int i = 1; i <= n; i ++ )
        pow2[i] = 1LL * pow2[i - 1] * inv2 % mod;

    int ans = 0;
    for (int i = 0; i <= A - 1; i ++ )
        ans = (ans + 1LL * CC(B - 1 + i, i) * pow2[B + i] % mod) % mod;

    printf("%d\n", ans);

    // printf("%d\n", qpow(2, mod - 2));

    return 0;
}
